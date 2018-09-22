#ifndef PYTHONWORKER_H
#define PYTHONWORKER_H

#include <cmath>
#include <Python.h>
#include <QObject>
#include <QThread>
#include <QAtomicInteger>


class PythonWorker : public QObject {
    Q_OBJECT
  public:
    explicit PythonWorker(QObject *parent = 0);
    QAtomicInteger<int> killed;

  private:
    PyGILState_STATE m_gil;

  signals:
    void WriteOutput(QString result);
    void SetInput(QString txt);
    void SetOutput(QString txt);
    void SetCode(QString txt);
    void SetSearchRegex(QString txt);
    void StartPythonRun();
    void EndPythonRun();

  public slots:
    void RunPython(const QString &startme, const QString &code);
    void StopPython();
};

#endif // PYTHONWORKER_H
