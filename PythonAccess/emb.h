#ifndef EMB_H
#define EMB_H
#include <cmath>
#include "Python.h"
#include "UI/mainview.h"
namespace emb {


typedef std::function<void(std::string)> StdOutWriteType;

PyObject* PyInitApiConnection(void);
PyObject* ApiWriteOutput(PyObject* self, PyObject* args);
PyObject* ApiSetCode(PyObject* self, PyObject* args);
PyObject* ApiGetCode(PyObject* self, PyObject* args);
PyObject* ApiSetOutput(PyObject* self, PyObject* args);
PyObject* ApiGetOutput(PyObject* self, PyObject* args);
PyObject* ApiGetAppPath(PyObject* self, PyObject* args);
PyObject* ApiSetInput(PyObject* self, PyObject* args);
PyObject* ApiGetInput(PyObject* self, PyObject* args);
void ResetStdOut();
void setMainView(MainView* _mainView);
MainView* getMainView();
void SetStdout(StdOutWriteType write);
PyMODINIT_FUNC PyInitEmbConnect(void);
PyObject* StdOutFlush(PyObject* self, PyObject* args);
PyObject* StdOutWrite(PyObject* self, PyObject* args);

}
#endif
