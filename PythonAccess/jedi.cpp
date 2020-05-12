#include "cstdlib"
#include "cmath"
#include "Python.h"
#include "jedi.h"

Jedi::Jedi(QObject* parent) : QObject(parent) {
}

void Jedi::SetJediGetCode(QString jediCode) {
    this->jediCode = jediCode;
}

QStringList Jedi::AutoComplete(const QString& code, long row, long col) {

    QStringList allCompletions;
    PyObject *pyPythonCode, *pyGetCompletionsFunc, *pyGetCompletionsArgs, *pyTemp, *pyCompletions, *pyMain;

    Py_Initialize();
    PyGILState_STATE d_gstate;
    d_gstate = PyGILState_Ensure();
    // Build the name object
    const char* pythonCode = code.toLocal8Bit().data();
    pyPythonCode = PyUnicode_FromString(pythonCode);
    pyMain = PyUnicode_FromString("__main__"); // default module

    pyGetCompletionsArgs = PyTuple_New(3);

    PyTuple_SetItem(pyGetCompletionsArgs, 0, pyPythonCode);
    PyTuple_SetItem(pyGetCompletionsArgs, 1, PyLong_FromLong(row));
    PyTuple_SetItem(pyGetCompletionsArgs, 2, PyLong_FromLong(col));

    // Run the preparation code
    PyRun_SimpleString(this->jediCode.toStdString().c_str());
    pyTemp = PyModule_GetDict(PyImport_GetModule(pyMain));


    pyGetCompletionsFunc = PyDict_GetItemString(pyTemp, (char*)"get_completions");
    pyCompletions = PyObject_CallObject(pyGetCompletionsFunc, pyGetCompletionsArgs);
    int len = PyList_Size(pyCompletions);
    for (int i = 0; i < len; i++) {
        PyObject* completion = PyList_GetItem(pyCompletions, i);
        PyObject* asciiComp = PyUnicode_AsASCIIString(completion);
        char* completionChars = PyBytes_AsString(asciiComp);
        allCompletions << completionChars;
    }


    Py_DECREF(pyPythonCode); // Delete PythonCode object
    PyGILState_Release(d_gstate);
    Py_Finalize();

    return allCompletions;
}
