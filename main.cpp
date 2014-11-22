#include <Python.h>
#include "mainview.h"
#include <QApplication>

static MainView* mainView;

static PyObject* emb_get_input(PyObject* self, PyObject* args)
{
    if (!PyArg_ParseTuple(args, ":numargs"))
        return NULL;

    return Py_BuildValue("s", mainView->GetInput().toStdString().c_str());
}

static PyObject* emb_set_output(PyObject* self, PyObject* args)
{
    char* data;
    if (!PyArg_ParseTuple(args, "s", &data))
        return NULL;

    mainView->SetOutput(QString(data));

    return Py_BuildValue("i", 0);
}
static PyObject* emb_write_output(PyObject* self, PyObject* args)
{
    char* data;
    if (!PyArg_ParseTuple(args, "s", &data))
        return NULL;

    mainView->WriteOutput(QString(data));

    return Py_BuildValue("i", 0);
}
static PyMethodDef EmbMethods[] = {
    { "get_input", emb_get_input, METH_VARARGS,
      "Get input textbox's content as as string" },
    { "set_output", emb_set_output, METH_VARARGS,
      "Set output textbox's content" },
    { "write_output", emb_write_output, METH_VARARGS,
      "Append to output, It does not automatically append a newline" },
    // end of method definitions
    { NULL, NULL, 0, NULL }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Py_SetProgramName(argv[0]);
    Py_Initialize();
    PySys_SetArgv(argc, argv);
    Py_InitModule("emb", EmbMethods);

    mainView = new MainView();
    mainView->show();

    int result = app.exec();

    Py_Finalize();

    return result;
}
