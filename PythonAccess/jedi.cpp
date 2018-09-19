#include "cstdlib"
#include "cmath"
#include "Python.h"
#include "jedi.h"
#include "QDebug"

Jedi::Jedi(const QString &getJediCode, QObject* parent) : QObject(parent)
{
    this->jediCode = getJediCode;
}

QStringList Jedi::AutoComplete(const QString& code, long row, long col)
{

   PyObject *pyPythonCode, *pyGetCompletionsFunc, *pyGetCompletionsArgs, *pyTemp, *pyCompletions;


   // Initialize the Python Interpreter
   Py_Initialize();


   // Build the name object
   const char* pythonCode = code.toStdString().c_str();
   pyPythonCode = PyUnicode_FromString(pythonCode);
   pyGetCompletionsArgs = PyTuple_New(3);
   PyTuple_SetItem(pyGetCompletionsArgs, 0, pyPythonCode);
   PyTuple_SetItem(pyGetCompletionsArgs, 1, PyLong_FromLong(row));
   PyTuple_SetItem(pyGetCompletionsArgs, 2, PyLong_FromLong(col));
   // Run the preparation code
   PyRun_SimpleString(this->jediCode.toStdString().c_str());
   pyTemp = PyEval_GetLocals();
   pyGetCompletionsFunc = PyMapping_GetItemString(pyTemp, "get_completions");
   pyCompletions = PyObject_CallObject(pyGetCompletionsFunc, pyGetCompletionsArgs);
   PyObject *temp = PyUnicode_AsASCIIString(pyCompletions);
   char* completions = PyBytes_AsString(temp);
   qDebug() << "Completions::" << completions;
   Py_DECREF(pyPythonCode); // Delete PythonCode object
   Py_Finalize();

   return QStringList();

}
