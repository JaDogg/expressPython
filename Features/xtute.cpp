#include "Features/xtute.h"


XTute::XTute(QObject *parent) : QObject(parent), m_questions(nullptr) {
}

void XTute::extractTo(QString& note, QTextStream& in)
{
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        if(line.startsWith(tr(SEP))) {
            break;
        }
        if (note.length() == 0) {
          note.append(line);
        } else {
          note.append("\n").append(line);
        }
    }
}

void XTute::Load(QString fileName)
{
    DeleteQuestions();
    m_questions = new QList<XQuestion*>();

    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString title, inp, code, out, note, line;
          inp = tr("");
          code = tr("");
          out = tr("");
          note = tr("");
          XQuestion* x = new XQuestion();

          // Title
          line = in.readLine();
          if (!line.startsWith(tr("#>|<")) || line.length() <= 4) {
              break;
          }
          title = line.mid(4);

          // Others
          extractTo(note, in);
          extractTo(inp, in);
          extractTo(out, in);
          extractTo(code, in);

          x->SetData(title, note, inp, out, code);
          m_questions->append(x);

       }
       inputFile.close();
       m_loaded = (m_questions->size() > 0);
    }
}

bool XTute::IsLoaded()
{
    return m_loaded;
}

void XTute::InitList(QListWidget *w, QProgressBar* p)
{
    w->clear();
    QListIterator<XQuestion*> i(*m_questions);
    int pass = 0;
    int total = m_questions->count();
    while (i.hasNext()) {
        XQuestion* x = i.next();
        QListWidgetItem* item;
        if (x->GetState() == 0) {
            item = new QListWidgetItem(m_i_tute, x->m_title, w);
        } else if (x->GetState() == 1) {
            pass++;
            item = new QListWidgetItem(m_i_tutepass, x->m_title, w);
        } else {
            item = new QListWidgetItem(m_i_tutefail, x->m_title, w);
        }
        w->addItem(item);
    }
    p->setValue((int)(pass * 100.0 / total));
}

void XTute::LoadQuestion(int index, CodeEditor *inp, CodeEditor *note, CodeEditor *code)
{
    if (index < 0) return;
    XQuestion* x = m_questions->at(index);
    inp->setPlainText(x->m_input);
    note->setPlainText(x->m_note);
    code->setPlainText(x->m_code);
    // Output is not loaded
}

void XTute::Mark(int index, QString answer, QListWidget *w, QProgressBar* p)
{
    if (index < 0) return;
    XQuestion* x = m_questions->value(index);
    x->SetPassed(x->m_output.compare(answer) == 0);
    InitList(w, p);
}

void XTute::DeleteQuestions()
{
    if(m_questions != nullptr) {
        QListIterator<XQuestion*> i(*m_questions);
        while (i.hasNext()) {
            XQuestion* x = i.next();
            delete x;
        }
        m_questions->clear();
        delete m_questions;
    }
}

void XTute::SetInput(int index, CodeEditor *inp)
{
    if (index < 0) return;
    XQuestion* x = m_questions->value(index);
    inp->setPlainText(x->m_input);
}

XTute::~XTute()
{
    DeleteQuestions();
}
