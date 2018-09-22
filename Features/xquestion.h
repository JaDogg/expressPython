#ifndef XQUESTION_H
#define XQUESTION_H

#include <QObject>

class XQuestion: public QObject {
    Q_OBJECT
  private:
    int m_state = 0;
  public:
    QString m_title;
    QString m_note;
    QString m_input;
    QString m_output;
    QString m_code;

    explicit XQuestion(QObject *parent = 0);
    void SetData(QString title, QString note, QString input, QString output, QString code);
    void SetPassed(bool isPassed);
    int GetState();
};

#endif // XQUESTION_H
