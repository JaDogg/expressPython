#ifndef KICKANTLRSYNTAXHIGHLIGHTER_H
#define KICKANTLRSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include "antlr4-runtime.h"
#include "ANTLR/Python3Lexer.h"
#include "ANTLR/Python3Parser.h"
#include "ANTLR/Python3Listener.h"
#include "ANTLR/customtoken.h"

//! Implementation of highlighting for Python code.
class ANTLRSyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

  public:
    ANTLRSyntaxHighlighter(QTextDocument *parent = 0);

    void SetSearchRegEx(const QString &text); 

  protected:
    void highlightBlock(const QString &text);
    std::vector<CustomToken> getTokens(const QString text);

  private:
    QHash<QString, bool> keywords;
    QHash<QString, bool> operators;
    QHash<QString, bool> braces;
    QHash<QString, bool> builtins;
    QHash<QString, bool> exceptions;
    QHash<QString, QTextCharFormat> basicStyles;
    QString mSearchRegex;
    QTextCharFormat mSearchHighlight;
    const int STRING = 1, NUMBER = 2;
    const QTextCharFormat
    getTextCharFormat(const QString &colorName, const QString &style = QString(),
                      const QString &backColorName = QString());
    void setStyles();
};

#endif
