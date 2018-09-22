#include "PythonAccess/emb.h"
#include "pythonworker.h"

PythonWorker::PythonWorker(QObject *parent) : QObject(parent) {
    this->killed.store(-2);
}

void PythonWorker::RunPython(const QString &startme, const QString &code) {
    emit StartPythonRun();
    PyImport_AppendInittab("emb", emb::PyInitEmbConnect);
    PyImport_AppendInittab("express_api", emb::PyInitApiConnection);
    Py_Initialize();
    PyImport_ImportModule("emb");

    emb::StdOutWriteType write = [this](std::string s) {
        emit this->WriteOutput(QString::fromStdString(s));
        QThread::msleep(10);
    };

    emb::IsInterruptedType isInterrupted = [this]() {
        return this->killed.load();
    };

    emb::SetStdout(write);
    emb::SetIsInterruptedCallback(isInterrupted);
    this->killed.store(0);
    m_gil = PyGILState_Ensure();
    PyRun_SimpleString(startme.toStdString().c_str());
    PyGILState_Release(m_gil);
    emb::ResetStdOut();
    Py_Finalize();
    emit EndPythonRun();
}

// https://stackoverflow.com/questions/1420957/stopping-embedded-python
int quit(void *) {
    PyErr_SetString(PyExc_KeyboardInterrupt, "...");
    return -1;
}

void PythonWorker::StopPython() {
    QThread::msleep(2000);
    PyGILState_STATE gil;
    gil = PyGILState_Ensure();
    Py_AddPendingCall(&quit, NULL);
    PyGILState_Release(gil);
    QThread::msleep(10);
}
