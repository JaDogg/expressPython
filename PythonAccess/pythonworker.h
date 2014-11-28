#ifndef PYTHONWORKER_H
#define PYTHONWORKER_H

#include <QObject>

class PythonWorker : public QObject
{
    Q_OBJECT
public:
    explicit PythonWorker(QObject *parent = 0);

signals:

public slots:

};

#endif // PYTHONWORKER_H
