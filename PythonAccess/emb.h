#ifndef EMB_H
#define EMB_H
#include <cmath>
#include "Python.h"
#include "UI/mainview.h"
#include "PythonAccess/pythonworker.h"
namespace emb {

typedef std::function<void(std::string)> StdOutWriteType;
typedef std::function<int()> IsInterruptedType;

PyObject *PyInitApiConnection(void);
PyObject *ApiWriteOutput(PyObject *self, PyObject *args);
PyObject *ApiSetCode(PyObject *self, PyObject *args);
PyObject *ApiGetCode(PyObject *self, PyObject *args);
PyObject *ApiSetOutput(PyObject *self, PyObject *args);
PyObject *ApiGetOutput(PyObject *self, PyObject *args);
PyObject *ApiGetAppPath(PyObject *self, PyObject *args);
PyObject *ApiSetInput(PyObject *self, PyObject *args);
PyObject *ApiGetInput(PyObject *self, PyObject *args);
PyObject *ApiSetSearchRegex(PyObject *self, PyObject *args);
PyObject *ApiInterruptRequested(PyObject *self, PyObject *args);
void ResetStdOut();
void setMainView(MainView *_mainView);
void setWorker(PythonWorker *_worker);
MainView *getMainView();
void SetStdout(StdOutWriteType write);
void SetIsInterruptedCallback(IsInterruptedType cb);
PyMODINIT_FUNC PyInitEmbConnect(void);
PyObject *StdOutFlush(PyObject *self, PyObject *args);
PyObject *StdOutWrite(PyObject *self, PyObject *args);
}
#endif
