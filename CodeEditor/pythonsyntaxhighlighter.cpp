/*  $Id: PythonSyntaxHighlighter.cpp 167 2013-11-03 17:01:22Z oliver $
 *
 *  This is a C++ port of the following PyQt example
 *  http://diotavelli.net/PyQtWiki/Python%20syntax%20highlighting
 *  C++ port by Frankie Simon (www.kickdrive.de, www.fuh-edv.de)
 *
 *  The following free software license applies for this file ("X11 license"):
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial
 *  portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 *  LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 *  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 *  USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  -----------Modified By Bhathiya Perera-------------
*/

#include "CodeEditor/PythonSyntaxHighlighter.h"

PythonSyntaxHighlighter::PythonSyntaxHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent)
{
    keywords = QStringList() << "and"
                             << "assert"
                             << "break"
                             << "class"
                             << "continue"
                             << "def"
                             << "del"
                             << "elif"
                             << "else"
                             << "except"
                             << "exec"
                             << "finally"
                             << "for"
                             << "from"
                             << "global"
                             << "if"
                             << "import"
                             << "in"
                             << "is"
                             << "lambda"
                             << "not"
                             << "or"
                             << "pass"
                             << "print"
                             << "raise"
                             << "return"
                             << "try"
                             << "while"
                             << "yield"
                             << "None"
                             << "True"
                             << "False";

    operators = QStringList() << "="
                              << "=="
                              << "!="
                              << "<"
                              << "<="
                              << ">"
                              << ">="
                              << "\\+"
                              << "-"
                              << "\\*"
                              << "/"
                              << "//"
                              << "%"
                              << "\\*\\*"
                              << "\\+="
                              << "-="
                              << "\\*="
                              << "/="
                              << "%="
                              << "\\^"
                              << "\\|"
                              << "&"
                              << "~"
                              << ">>"
                              << "<<";

    braces = QStringList() << "{"
                           << "}"
                           << "\\("
                           << "\\)"
                           << "\\["
                           << "\\]";

    setStyles();

    triSingleQuote.setPattern("'''");
    triDoubleQuote.setPattern("\"\"\"");

    initializeRules();
}

void PythonSyntaxHighlighter::setStyles()
{
    basicStyles.insert("keyword", getTextCharFormat("orange", "bold"));
    basicStyles.insert("operator", getTextCharFormat("red"));
    basicStyles.insert("brace", getTextCharFormat("red", "bold"));
    basicStyles.insert("defclass", getTextCharFormat("white", "bold"));
    basicStyles.insert("string", getTextCharFormat("magenta"));
    basicStyles.insert("string2", getTextCharFormat("darkMagenta"));
    basicStyles.insert("comment", getTextCharFormat("darkGreen", "bold"));
    basicStyles.insert("self", getTextCharFormat("white", "bold"));
    basicStyles.insert("numbers", getTextCharFormat("cyan"));
    basicStyles.insert("bugs", getTextCharFormat("yellow", "bold", "red"));
}

void PythonSyntaxHighlighter::initializeRules()
{
    foreach (QString currKeyword, keywords) {
        rules.append(HighlightingRule(QString("\\b%1\\b").arg(currKeyword), 0, basicStyles.value("keyword")));
    }
    foreach (QString currOperator, operators) {
        rules.append(HighlightingRule(QString("%1").arg(currOperator), 0, basicStyles.value("operator")));
    }
    foreach (QString currBrace, braces) {
        rules.append(HighlightingRule(QString("%1").arg(currBrace), 0, basicStyles.value("brace")));
    }
    // 'self'
    rules.append(HighlightingRule("\\bself\\b", 0, basicStyles.value("self")));

    // Double-quoted string, possibly containing escape sequences
    rules.append(HighlightingRule("\"[^\"\\\\]*(\\\\.[^\"\\\\]*)*\"", 0, basicStyles.value("string")));
    // Single-quoted string, possibly containing escape sequences
    rules.append(HighlightingRule("'[^'\\\\]*(\\\\.[^'\\\\]*)*'", 0, basicStyles.value("string")));

    // 'def' followed by an identifier
    rules.append(HighlightingRule("\\bdef\\b\\s*(\\w+)", 1, basicStyles.value("defclass")));
    //  'class' followed by an identifier
    rules.append(HighlightingRule("\\bclass\\b\\s*(\\w+)", 1, basicStyles.value("defclass")));

    // Numeric literals
    rules.append(HighlightingRule("\\b[+-]?[0-9]+[lL]?\\b", 0, basicStyles.value("numbers")));
    rules.append(HighlightingRule("\\b[+-]?0[xX][0-9A-Fa-f]+[lL]?\\b", 0, basicStyles.value("numbers")));
    rules.append(HighlightingRule("\\b[+-]?[0-9]+(?:\\.[0-9]+)?(?:[eE][+-]?[0-9]+)?\\b", 0, basicStyles.value("numbers")));

    // tab and space mixed
    rules.append(HighlightingRule("[^\\n]*(?:\\t | \\t)[^\\n]*", 0, basicStyles.value("bugs")));

    // From '#' until a newline
    rules.append(HighlightingRule("#[^\\n]*", 0, basicStyles.value("comment")));
}

void PythonSyntaxHighlighter::highlightBlock(const QString& text)
{
    foreach (HighlightingRule currRule, rules) {
        int idx = currRule.pattern.indexIn(text, 0);
        while (idx >= 0) {
            // Get index of Nth match
            idx = currRule.pattern.pos(currRule.nth);
            int length = currRule.pattern.cap(currRule.nth).length();
            setFormat(idx, length, currRule.format);
            idx = currRule.pattern.indexIn(text, idx + length);
        }
    }

    setCurrentBlockState(0);

    // Do multi-line strings
    bool isInMultilne = matchMultiline(text, triSingleQuote, 1, basicStyles.value("string2"));
    if (!isInMultilne)
        isInMultilne = matchMultiline(text, triDoubleQuote, 2, basicStyles.value("string2"));
}

bool PythonSyntaxHighlighter::matchMultiline(const QString& text, const QRegExp& delimiter, const int inState, const QTextCharFormat& style)
{
    int start = -1;
    int add = -1;
    int end = -1;
    int length = 0;

    // If inside triple-single quotes, start at 0
    if (previousBlockState() == inState) {
        start = 0;
        add = 0;
    }
    // Otherwise, look for the delimiter on this line
    else {
        start = delimiter.indexIn(text);
        // Move past this match
        add = delimiter.matchedLength();
    }

    // As long as there's a delimiter match on this line...
    while (start >= 0) {
        // Look for the ending delimiter
        end = delimiter.indexIn(text, start + add);
        // Ending delimiter on this line?
        if (end >= add) {
            length = end - start + add + delimiter.matchedLength();
            setCurrentBlockState(0);
        }
        // No; multi-line string
        else {
            setCurrentBlockState(inState);
            length = text.length() - start + add;
        }
        // Apply formatting and look for next
        setFormat(start, length, style);
        start = delimiter.indexIn(text, start + length);
    }
    // Return True if still inside a multi-line string, False otherwise
    if (currentBlockState() == inState)
        return true;
    else
        return false;
}

const QTextCharFormat PythonSyntaxHighlighter::getTextCharFormat(
    const QString& colorName, const QString& style, const QString& backColorName)
{
    QTextCharFormat charFormat;
    QColor color(colorName);
    charFormat.setForeground(color);

    if (!backColorName.isEmpty()) {
        QColor backColor(backColorName);
        charFormat.setBackground(backColor);
    }
    if (style.contains("bold", Qt::CaseInsensitive))
        charFormat.setFontWeight(QFont::Bold);
    if (style.contains("italic", Qt::CaseInsensitive))
        charFormat.setFontItalic(true);
    return charFormat;
}
