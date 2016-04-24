#include "Features/xquestion.h"

XQuestion::XQuestion(QObject *parent) : QObject(parent)
{
}

void XQuestion::SetData(QString title, QString note, QString input, QString output, QString code)
{
    m_title = title;
    m_note = note;
    m_input = input;
    m_output = output;
    m_code = code;
}

void XQuestion::SetPassed(bool isPassed)
{
    if(isPassed) {
        m_state = 1;
    } else {
        m_state = 2;
    }
}

int XQuestion::GetState()
{
    return m_state;
}
