/****************************************************************************
**
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
** -----------Modified By Bhathiya Perera-------------
****************************************************************************/

#include <QtWidgets>
#include <QDebug>
#include <QTextStream>
#include "CodeEditor/codeeditor.h"

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent), m_completer(0), m_jediCompleter(0) {
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this,
            SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect, int)), this,
            SLOT(updateLineNumberArea(QRect, int)));

    updateLineNumberAreaWidth(0);

    QPalette p = this->palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::white);
    this->setPalette(p);
}

void CodeEditor::setCompleter(QCompleter *completer) {
    if (m_completer)
        QObject::disconnect(m_completer, nullptr, this, 0);

    m_completer = completer;

    if (!m_completer)
        return;

    m_completer->setWidget(this);
    QObject::connect(m_completer, SIGNAL(activated(QString)), this,
                     SLOT(insertCompletion(QString)));
}

void CodeEditor::setJediCompleter(QCompleter *jediCompleter, const QString& getJediCode) {
    if (m_jediCompleter) {
        QObject::disconnect(m_jediCompleter, 0, this, 0);
    } else {
        m_jedi = new Jedi(this);
        m_jedi->SetJediGetCode(QString(getJediCode.toStdString().c_str()));
    }

    m_jediCompleter = jediCompleter;

    if (!m_jediCompleter)
        return;

    m_jediCompleter->setWidget(this);
    QObject::connect(m_jediCompleter, SIGNAL(activated(QString)), this,
                     SLOT(insertCompletion(QString)));
}

QCompleter *CodeEditor::completer() const {
    return this->m_completer;
}

QCompleter *CodeEditor::jediCompleter() const {
    return this->m_jediCompleter;
}

void CodeEditor::insertCompletion(const QString &completion) {
    QCompleter* q;
    if (m_jediCompleter->popup()->isVisible()) {
        q = m_jediCompleter;
    } else {
        q = m_completer;
    }
    if (q->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = q->completionPrefix().length();
    tc.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, extra);
    tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
    tc.insertText(completion);
    tc.movePosition(QTextCursor::Right);
    setTextCursor(tc);
}

QString CodeEditor::textUnderCursor() const {
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void CodeEditor::focusInEvent(QFocusEvent *e) {
    if (m_completer)
        m_completer->setWidget(this);
    QPlainTextEdit::focusInEvent(e);
}

int CodeEditor::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */) {
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy) {
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e) {
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(
        QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::SelectLineMarginBlock() {
    int start, end;

    // get current positions
    start = this->textCursor().selectionStart();
    end = this->textCursor().selectionEnd();

    QTextCursor cursor(this->document());

    // move cursor to begin of the line, of the line
    // start position is located.
    cursor.clearSelection();
    cursor.setPosition(start);
    cursor.movePosition(QTextCursor::StartOfLine);
    this->setTextCursor(cursor);
    start = this->textCursor().selectionStart();

    // move cursor to end of the line, of the line
    // end position is located.
    cursor.setPosition(end);
    cursor.movePosition(QTextCursor::EndOfLine);
    this->setTextCursor(cursor);
    end = this->textCursor().selectionEnd();

    // select line margin block
    cursor.setPosition(start, QTextCursor::KeepAnchor);
    this->setTextCursor(cursor);
}
QString CodeEditor::GetLine() {
    int start = this->textCursor().position();
    QTextCursor cursor(this->document());
    cursor.setPosition(start);
    cursor.movePosition(QTextCursor::StartOfLine);
    this->setTextCursor(cursor);
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    this->setTextCursor(cursor);
    QString text = this->textCursor().selection().toPlainText();
    cursor.movePosition(QTextCursor::EndOfLine);
    this->setTextCursor(cursor);
    return text;
}
bool CodeEditor::KeepIndent() {
    if (this->textCursor().hasSelection() || !this->textCursor().atBlockEnd()) {
        return false;
    }
    QRegExp spaces("(\\s*).*");

    spaces.indexIn(GetLine());
    this->insertPlainText(tr("\n"));
    this->insertPlainText(spaces.cap(1));

    return true;
}
void CodeEditor::keyPressEvent(QKeyEvent *e) {

    bool no_process = false;

    if (m_jediCompleter && m_completer && m_jediCompleter->popup()->isVisible() && m_completer->popup()->isVisible()) {
        m_jediCompleter->popup()->hide();
        e->ignore();
        return;
    } else if (m_jediCompleter && m_jediCompleter->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
        default:
            break;
        }
    } else if (m_completer && m_completer->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
        default:
            break;
        }
    } else {
        switch (e->key()) {
        case Qt::Key_Backtab:
            SelectLineMarginBlock();
            {
                QString text("");
                QStringList lines = this->textCursor().selection().toPlainText().split(
                                        QRegExp("\n|\r\n|\r"));
                foreach (QString line, lines) {
                    line.replace(QRegExp("^(    |   |  | )(.*)"), "\\2");
                    text.append(line);
                    text.append("\n");
                }
                text.truncate(text.length() - 1);
                this->textCursor().insertText(text);
            }
            no_process = true;
            break;
        case Qt::Key_Tab:
            if (this->textCursor().hasSelection()) {
                SelectLineMarginBlock();
                {
                    QString text("");
                    QStringList lines = this->textCursor().selection().toPlainText().split(
                                            QRegExp("\n|\r\n|\r"));
                    foreach (QString line, lines) {
                        text.append("    ");
                        text.append(line);
                        text.append("\n");
                    }
                    text.truncate(text.length() - 1);
                    this->textCursor().insertText(text);
                }
            } else {
                this->insertPlainText("    ");
            }
            no_process = true;
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if (!KeepIndent()) {
                QPlainTextEdit::keyPressEvent(e);
                return;
            } else {
                no_process = true;
            }
        }
    }

    // CTRL+Space
    bool ctrlSpace = ((e->modifiers() & Qt::ControlModifier) &&
                      e->key() == Qt::Key_Space);
    if ((!m_jediCompleter || !ctrlSpace) && !no_process)
        QPlainTextEdit::keyPressEvent(e);

    const bool ctrlOrShift =
        e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);

    // Do nothing If it's just ctrl or shift, or completer or jedi isn't there
    // If it is ctrl or shift we don't need to hide the auto complete
    if (!m_jediCompleter || !m_completer || (ctrlOrShift && e->text().isEmpty())) {
        return;
    }

    // Some other modifier like Escape, Return or Enter?
    bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    // Hide if Escape, Return or Enter or text is less than 2 characters
    if (!ctrlSpace &&
            (hasModifier || e->text().isEmpty() || completionPrefix.length() < 2)) {
        m_completer->popup()->hide();
        m_jediCompleter->popup()->hide();
        return;
    }

    if (ctrlSpace && completionPrefix != m_jediCompleter->completionPrefix()) {
        // Now is the time to populate jedi
        m_jediCompleter->setCompletionPrefix(completionPrefix);
        m_jediCompleter->popup()->setCurrentIndex(m_completer->completionModel()->index(0, 0));
    }
    if (completionPrefix != m_completer->completionPrefix()) {
        m_completer->setCompletionPrefix(completionPrefix);
        m_completer->popup()->setCurrentIndex(m_completer->completionModel()->index(0, 0));
    }
    if (ctrlSpace) {
        QRect cr = cursorRect();
        cr.setWidth(m_completer->popup()->sizeHintForColumn(0) +
                    m_completer->popup()->verticalScrollBar()->sizeHint().width());
        m_completer->popup()->hide();
        m_jediCompleter->popup()->hide();
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        int row = this->textCursor().blockNumber();
        int col = this->textCursor().positionInBlock();
        QStringList words = m_jedi->AutoComplete(this->toPlainText(), row, col);
        QStringListModel *updatedJedi = new QStringListModel(words, m_jedi);
        m_jediCompleter->setModel(updatedJedi);
        QApplication::restoreOverrideCursor();
        m_jediCompleter->complete(cr);
    } else {
        QRect cr = cursorRect();
        cr.setWidth(m_completer->popup()->sizeHintForColumn(0) +
                    m_completer->popup()->verticalScrollBar()->sizeHint().width());
        m_jediCompleter->popup()->hide();
        m_completer->complete(cr);
    }
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::darkGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int)blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int)blockBoundingRect(block).height();
        ++blockNumber;
    }
}
