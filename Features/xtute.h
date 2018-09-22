#ifndef XTUTE_H
#define XTUTE_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QIODevice>
#include <QFile>
#include <QApplication>
#include <QListWidget>
#include <QProgressBar>
#include <QTextStream>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include "CodeEditor/codeeditor.h"
#include "xquestion.h"

#define SEP "#>>>>>>>>>>>>>><<<<<<<<<<<<<<<#"

class XTute : public QObject {
    Q_OBJECT
  public:
    explicit XTute(QObject *parent = 0);
    void Load(QString fileName);
    bool IsLoaded();
    void InitList(QListWidget *w, QProgressBar *p);
    void LoadQuestion(int index, CodeEditor *inp, CodeEditor *note, CodeEditor *code);
    void Mark(int index, QString answer, QListWidget *w, QProgressBar *p);
    void DeleteQuestions();
    void SetInput(int index, CodeEditor* inp);
    ~XTute();
  private:
    const QIcon m_i_tute = QIcon(QPixmap(":/data/Icons/Tute.png"));
    const QIcon m_i_tutepass = QIcon(QPixmap(":/data/Icons/TutePass.png"));
    const QIcon m_i_tutefail = QIcon(QPixmap(":/data/Icons/TuteFail.png"));

    void extractTo(QString& note, QTextStream& in);
    QList<XQuestion*> *m_questions;
    bool m_loaded = false;
};

#endif // XTUTE_H
