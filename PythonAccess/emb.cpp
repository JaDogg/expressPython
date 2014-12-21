// --------------------------------------------------------------------------
// Copyright (C) 2011 Mateusz Loskot <mateusz@loskot.net>
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Blog article: http://mateusz.loskot.net/?p=2819
// --------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <functional>
#include <iostream>
#include <string>

#include "PythonAccess/emb.h"

namespace emb {
MainView *mainView;
PythonWorker *worker;
void setMainView(MainView *_mainView) { mainView = _mainView; }
void setWorker(PythonWorker *_worker) { worker = _worker; }
MainView *getMainView() { return mainView; }
struct StdOut {
  PyObject_HEAD StdOutWriteType write;
};
PyObject *StdOutWrite(PyObject *self, PyObject *args) {
  std::size_t written(0);
  StdOut *selfimpl = reinterpret_cast<StdOut *>(self);
  if (selfimpl->write) {
    char *data;
    if (!PyArg_ParseTuple(args, "s", &data))
      return 0;
    std::string str(data);
    selfimpl->write(str);
    written = str.size();
  }
  return PyLong_FromSize_t(written);
}
PyObject *StdOutFlush(PyObject *self, PyObject *args) {
  // no-op
  return Py_BuildValue("");
}
PyMethodDef stdOutMethods[] = {
    {"write", StdOutWrite, METH_VARARGS, "sys.stdout.write"},
    {"flush", StdOutFlush, METH_VARARGS, "sys.stdout.flush"},
    {0, 0, 0, 0} // sentinel
};
PyTypeObject StdoutType = {
    PyVarObject_HEAD_INIT(0, 0) "emb.StdoutType", /* tp_name */
    sizeof(StdOut),                               /* tp_basicsize */
    0,                                            /* tp_itemsize */
    0,                                            /* tp_dealloc */
    0,                                            /* tp_print */
    0,                                            /* tp_getattr */
    0,                                            /* tp_setattr */
    0,                                            /* tp_reserved */
    0,                                            /* tp_repr */
    0,                                            /* tp_as_number */
    0,                                            /* tp_as_sequence */
    0,                                            /* tp_as_mapping */
    0,                                            /* tp_hash */
    0,                                            /* tp_call */
    0,                                            /* tp_str */
    0,                                            /* tp_getattro */
    0,                                            /* tp_setattro */
    0,                                            /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                           /* tp_flags */
    "emb.Stdout objects",                         /* tp_doc */
    0,                                            /* tp_traverse */
    0,                                            /* tp_clear */
    0,                                            /* tp_richcompare */
    0,                                            /* tp_weaklistoffset */
    0,                                            /* tp_iter */
    0,                                            /* tp_iternext */
    stdOutMethods,                                /* tp_methods */
    0,                                            /* tp_members */
    0,                                            /* tp_getset */
    0,                                            /* tp_base */
    0,                                            /* tp_dict */
    0,                                            /* tp_descr_get */
    0,                                            /* tp_descr_set */
    0,                                            /* tp_dictoffset */
    0,                                            /* tp_init */
    0,                                            /* tp_alloc */
    0,                                            /* tp_new */
};
PyModuleDef embModule = {
    PyModuleDef_HEAD_INIT, "emb", 0, -1, 0,
};
// Internal state
PyObject *gStdOut;
PyObject *gStdOutSaved;
PyObject *gStdErrSaved;
PyMODINIT_FUNC PyInitEmbConnect(void) {
  gStdOut = 0;
  gStdOutSaved = 0;
  gStdErrSaved = 0;
  StdoutType.tp_new = PyType_GenericNew;
  if (PyType_Ready(&StdoutType) < 0)
    return 0;
  PyObject *m = PyModule_Create(&embModule);
  if (m) {
    Py_INCREF(&StdoutType);
    PyModule_AddObject(m, "Stdout", reinterpret_cast<PyObject *>(&StdoutType));
  }
  return m;
}
void SetStdout(StdOutWriteType write) {
  if (!gStdOut) {
    gStdOutSaved = PySys_GetObject("stdout");
    gStdErrSaved = PySys_GetObject("stderr");
    gStdOut = StdoutType.tp_new(&StdoutType, 0, 0);
  }
  StdOut *impl = reinterpret_cast<StdOut *>(gStdOut);
  impl->write = write;
  PySys_SetObject("stdout", gStdOut);
  PySys_SetObject("stderr", gStdOut);
}
void ResetStdOut() {
  if (gStdOutSaved)
    PySys_SetObject("stdout", gStdOutSaved);
  if (gStdErrSaved)
    PySys_SetObject("stderr", gStdErrSaved);

  Py_XDECREF(gStdOut);
  gStdOut = 0;
}
//--------------------------------------------------------------------
// Embedded APIs
//--------------------------------------------------------------------
PyObject *ApiGetInput(PyObject *self, PyObject *args) {
  if (!PyArg_ParseTuple(args, ":numargs"))
    return NULL;

  return Py_BuildValue("s", mainView->GetInput().toStdString().c_str());
}
PyObject *ApiSetInput(PyObject *self, PyObject *args) {
  char *data;
  if (!PyArg_ParseTuple(args, "s", &data))
    return NULL;

  emit worker->SetInput(QString(data));

  return Py_BuildValue("i", 0);
}
PyObject *ApiGetAppPath(PyObject *self, PyObject *args) {
  if (!PyArg_ParseTuple(args, ":numargs"))
    return NULL;

  return Py_BuildValue(
      "s", QCoreApplication::applicationDirPath().toStdString().c_str());
}
PyObject *ApiGetOutput(PyObject *self, PyObject *args) {
  if (!PyArg_ParseTuple(args, ":numargs"))
    return NULL;

  return Py_BuildValue("s", mainView->GetOutput().toStdString().c_str());
}

PyObject *ApiSetOutput(PyObject *self, PyObject *args) {
  char *data;
  if (!PyArg_ParseTuple(args, "s", &data))
    return NULL;

  emit worker->SetOutput(QString(data));

  return Py_BuildValue("i", 0);
}
PyObject *ApiGetCode(PyObject *self, PyObject *args) {
  if (!PyArg_ParseTuple(args, ":numargs"))
    return NULL;

  return Py_BuildValue("s", mainView->GetCode().toStdString().c_str());
}

PyObject *ApiSetCode(PyObject *self, PyObject *args) {
  char *data;
  if (!PyArg_ParseTuple(args, "s", &data))
    return NULL;

  emit worker->SetCode(QString(data));

  return Py_BuildValue("i", 0);
}

PyObject *ApiSetSearchRegex(PyObject *self, PyObject *args) {
  char *data;
  if (!PyArg_ParseTuple(args, "s", &data))
    return NULL;

  emit worker->SetSearchRegex(QString(data));

  return Py_BuildValue("i", 0);
}

PyObject *ApiWriteOutput(PyObject *self, PyObject *args) {
  char *data;
  if (!PyArg_ParseTuple(args, "s", &data))
    return NULL;

  emit worker->WriteOutput(QString(data));

  return Py_BuildValue("i", 0);
}

PyMethodDef apiMethods[] = {
    {"get_input", ApiGetInput, METH_VARARGS, "Get input textbox's content"},
    {"set_input", ApiSetInput, METH_VARARGS, "Set input textbox's content"},

    {"get_apppath", ApiGetAppPath, METH_VARARGS, "Get application path"},

    {"get_output", ApiGetOutput, METH_VARARGS, "Get output textbox's content"},
    {"set_output", ApiSetOutput, METH_VARARGS, "Set output textbox's content"},

    {"get_code", ApiGetCode, METH_VARARGS, "Get code textbox's content"},
    {"set_code", ApiSetCode, METH_VARARGS, "Get code textbox's content"},
    {"set_search_regex", ApiSetSearchRegex, METH_VARARGS,
     "Set highlight RegEx"},

    {"write_output", ApiWriteOutput, METH_VARARGS,
     "Append to output, It does not automatically add a newline"},
    // end of method definitions
    {NULL, NULL, 0, NULL}};

PyModuleDef apiModule = {PyModuleDef_HEAD_INIT, "expressApi", NULL,
                         -1,                    apiMethods,   NULL,
                         NULL,                  NULL,         NULL};
PyObject *PyInitApiConnection(void) { return PyModule_Create(&apiModule); }
}

#pragma GCC diagnostic warning "-Wunused-parameter"
#pragma GCC diagnostic warning "-Wmissing-field-initializers"
