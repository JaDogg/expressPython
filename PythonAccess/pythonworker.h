#ifndef PYTHONWORKER_H
#define PYTHONWORKER_H

#include <QObject>

class PythonWorker : public QObject
{
    Q_OBJECT
public:
    explicit PythonWorker(QObject *parent = 0);

private:

signals:
    void WriteOutput(QString result);
    void SetInput(QString txt);
    void SetOutput(QString txt);
    void SetCode(QString txt);
    void StartPythonRun();
    void EndPythonRun();

public slots:
    void RunPython(const QString &startme,const QString &code);
};

#endif // PYTHONWORKER_H
