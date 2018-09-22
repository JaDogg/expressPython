#include <QtWidgets>
#include <QDebug>
#include <QTextStream>
#include "CodeEditor/codelineedit.h"

CodeLineEdit::CodeLineEdit(QWidget *parent) : QPlainTextEdit(parent) {
    setTabChangesFocus(true);
    setWordWrapMode(QTextOption::NoWrap);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setFixedHeight(sizeHint().height());
    QPalette p = this->palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::white);
    this->setPalette(p);
}
void CodeLineEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter ||
            event->key() == Qt::Key_Tab || event->key() == Qt::Key_Backtab) {
        event->ignore();
    } else {
        QPlainTextEdit::keyPressEvent(event);
    }
}

QSize CodeLineEdit::sizeHint() const {
    QFontMetrics fm(font());
    int h = qMax(fm.height(), 14) + 4;
    int w = fm.width(QLatin1Char('x')) * 17 + 4;
    QStyleOption opt;
    opt.initFrom(this);
    return (style()->sizeFromContents(
                QStyle::CT_LineEdit, &opt,
                QSize(w, h).expandedTo(QApplication::globalStrut()), this));
}

void CodeLineEdit::wheelEvent(QWheelEvent *e) {
    e->ignore();
}
void CodeLineEdit::dragEnterEvent(QDragEnterEvent *e) {
    e->ignore();
}
void CodeLineEdit::dragLeaveEvent(QDragLeaveEvent *e) {
    e->ignore();
}
void CodeLineEdit::dragMoveEvent(QDragMoveEvent *e) {
    e->ignore();
}
void CodeLineEdit::dropEvent(QDropEvent *e) {
    e->ignore();
}
void CodeLineEdit::mouseMoveEvent(QMouseEvent *e) {
    e->ignore();
}
