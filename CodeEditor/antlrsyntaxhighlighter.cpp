/*  $Id: ANTLRSyntaxHighlighter.cpp 167 2013-11-03 17:01:22Z oliver $
 *
 *  This is a C++ port of the following PyQt example
 *  http://diotavelli.net/PyQtWiki/Python%20syntax%20highlighting
 *  C++ port by Frankie Simon (www.kickdrive.de, www.fuh-edv.de)
 *
 *  The following free software license applies for this file ("X11 license"):
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software
 *  and associated documentation files (the "Software"), to deal in the Software
 *without restriction,
 *  including without limitation the rights to use, copy, modify, merge,
 *publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *Software is furnished to do so,
 *  subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *all copies or substantial
 *  portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT
 *  LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 *PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN
 *  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *WITH THE SOFTWARE OR THE
 *  USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  -----------Modified By Bhathiya Perera-------------
*/

#include "CodeEditor/antlrsyntaxhighlighter.h"
#include <QDebug>

ANTLRSyntaxHighlighter::ANTLRSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent) {

    keywords = {{"and", true},
                 {"assert", true},
                 {"break", true},
                 {"class", true},
                 {"continue", true},
                 {"def", true},
                 {"del", true},
                 {"elif", true},
                 {"else", true},
                 {"except", true},
                 {"exec", true},
                 {"finally", true},
                 {"for", true},
                 {"from", true},
                 {"global", true},
                 {"if", true},
                 {"import", true},
                 {"in", true},
                 {"is", true},
                 {"lambda", true},
                 {"not", true},
                 {"or", true},
                 {"pass", true},
                 {"raise", true},
                 {"return", true},
                 {"try", true},
                 {"while", true},
                 {"yield", true},
                 {"None", true},
                 {"True", true},
                 {"False", true}};

    operators = {{"==", true},
                  {"<>", true},
                  {"...", true},
                  {".", true},
                  {"!=", true},
                  {"<", true},
                  {"<=", true},
                  {">", true},
                  {">=", true},
                  {"+", true},
                  {"-", true},
                  {"*", true},
                  {"/", true},
                  {"//", true},
                  {"%", true},
                  {"**", true},
                  {"+=", true},
                  {"-=", true},
                  {"*=", true},
                  {"/=", true},
                  {"%=", true},
                  {"^", true},
                  {"|", true},
                  {"&", true},
                  {"~", true},
                  {">>", true},
                  {"<<", true},
                  {">>=", true},
                  {"<<=", true},
                  {"=", true}};

    braces = {{":", true},
               {";", true},
               {",", true},
               {"@", true},
               {"{", true},
               {"}", true},
               {"(", true},
               {")", true},
               {"[", true},
               {"]", true}};

    builtins = {{"abs", true},
                 {"divmod", true},
                 {"input", true},
                 {"open", true},
                 {"staticmethod", true},
                 {"all", true},
                 {"enumerate", true},
                 {"int", true},
                 {"ord", true},
                 {"str", true},
                 {"any", true},
                 {"eval", true},
                 {"isinstance", true},
                 {"pow", true},
                 {"sum", true},
                 {"basestring", true},
                 {"execfile", true},
                 {"issubclass", true},
                 {"print", true},
                 {"super", true},
                 {"bin", true},
                 {"file", true},
                 {"iter", true},
                 {"property", true},
                 {"tuple", true},
                 {"bool", true},
                 {"filter", true},
                 {"len", true},
                 {"range", true},
                 {"type", true},
                 {"bytearray", true},
                 {"float", true},
                 {"list", true},
                 {"raw_input", true},
                 {"unichr", true},
                 {"callable", true},
                 {"format", true},
                 {"locals", true},
                 {"reduce", true},
                 {"unicode", true},
                 {"chr", true},
                 {"frozenset", true},
                 {"long", true},
                 {"reload", true},
                 {"vars", true},
                 {"classmethod", true},
                 {"getattr", true},
                 {"map", true},
                 {"repr", true},
                 {"xrange", true},
                 {"cmp", true},
                 {"globals", true},
                 {"max", true},
                 {"reversed", true},
                 {"zip", true},
                 {"compile", true},
                 {"hasattr", true},
                 {"memoryview", true},
                 {"round", true},
                 {"__import__", true},
                 {"complex", true},
                 {"hash", true},
                 {"min", true},
                 {"set", true},
                 {"apply", true},
                 {"delattr", true},
                 {"help", true},
                 {"next", true},
                 {"setattr", true},
                 {"buffer", true},
                 {"dict", true},
                 {"hex", true},
                 {"object", true},
                 {"slice", true},
                 {"coerce", true},
                 {"dir", true},
                 {"id", true},
                 {"oct", true},
                 {"sorted", true},
                 {"intern", true}};

    exceptions = {{"BaseException", true},
                   {"SystemExit", true},
                   {"KeyboardInterrupt", true},
                   {"GeneratorExit", true},
                   {"Exception", true},
                   {"StopIteration", true},
                   {"ArithmeticError", true},
                   {"FloatingPointError", true},
                   {"OverflowError", true},
                   {"ZeroDivisionError", true},
                   {"AssertionError", true},
                   {"AttributeError", true},
                   {"BufferError", true},
                   {"EOFError", true},
                   {"ImportError", true},
                   {"LookupError", true},
                   {"IndexError", true},
                   {"KeyError", true},
                   {"MemoryError", true},
                   {"NameError", true},
                   {"UnboundLocalError", true},
                   {"OSError", true},
                   {"BlockingIOError", true},
                   {"ChildProcessError", true},
                   {"ConnectionError", true},
                   {"BrokenPipeError", true},
                   {"ConnectionAbortedError", true},
                   {"ConnectionRefusedError", true},
                   {"ConnectionResetError", true},
                   {"FileExistsError", true},
                   {"FileNotFoundError", true},
                   {"InterruptedError", true},
                   {"IsADirectoryError", true},
                   {"NotADirectoryError", true},
                   {"PermissionError", true},
                   {"ProcessLookupError", true},
                   {"TimeoutError", true},
                   {"ReferenceError", true},
                   {"RuntimeError", true},
                   {"NotImplementedError", true},
                   {"SyntaxError", true},
                   {"IndentationError", true},
                   {"TabError", true},
                   {"SystemError", true},
                   {"TypeError", true},
                   {"ValueError", true},
                   {"UnicodeError", true},
                   {"UnicodeDecodeError", true},
                   {"UnicodeEncodeError", true},
                   {"UnicodeTranslateError", true},
                   {"Warning", true},
                   {"DeprecationWarning", true},
                   {"PendingDeprecationWarning", true},
                   {"RuntimeWarning", true},
                   {"SyntaxWarning", true},
                   {"UserWarning", true},
                   {"FutureWarning", true},
                   {"ImportWarning", true},
                   {"UnicodeWarning", true},
                   {"BytesWarning", true},
                   {"ResourceWarning", true}};

    setStyles();
    mSearchRegex = tr("");
    mSearchHighlight = getTextCharFormat("black", "bold", "yellow");
}

void ANTLRSyntaxHighlighter::setStyles() {
    basicStyles.insert("keyword", getTextCharFormat("orange", "bold"));
    basicStyles.insert("operator", getTextCharFormat("yellow", "bold"));
    basicStyles.insert("builtins", getTextCharFormat("lightblue", "underline"));
    basicStyles.insert("brace", getTextCharFormat("red", "bold"));
    basicStyles.insert("string", getTextCharFormat("magenta"));
    basicStyles.insert("stringlong", getTextCharFormat("magenta", "bold"));
    basicStyles.insert("comment", getTextCharFormat("darkgreen", "bold"));
    basicStyles.insert("special", getTextCharFormat("teal", "bold"));
    basicStyles.insert("numbers", getTextCharFormat("cyan"));
    basicStyles.insert("bugs", getTextCharFormat("yellow", "bold", "red"));
    basicStyles.insert("hackish", getTextCharFormat("royalblue", "bold"));
    basicStyles.insert("except", getTextCharFormat("royalblue", "underline"));
    basicStyles.insert("private", getTextCharFormat("white", "italic"));
}

void ANTLRSyntaxHighlighter::highlightBlock(const QString &text) {
    auto tokens = getTokens(text);

    for(auto token : tokens) {
     auto text = token.getText();
     auto type = token.getType();
     auto startIndex = token.getStartIndex();
     auto stopIndex = token.getStopIndex();

     if(keywords[text]) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["keyword"]);
     }
     else if(operators[text]) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["operator"]);
     }
     else if(braces[text]) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["brace"]);
     }
     else if(builtins[text]) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["builtins"]);
     }
     else if(exceptions[text]) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["except"]);
     }
     else if(type == Python3Lexer::STRING_SHORT) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["string"]);
     }
     else if(type == Python3Lexer::STRING_LONG) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["stringlong"]);
     }
     else if(type == Python3Lexer::NUMBER) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["numbers"]);
     }
     else if(type == Python3Lexer::COMMENTS) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["comment"]);
     }
     else if(type == Python3Lexer::PRIVATE) {
        setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["private"]);
     }
     else if(type == Python3Lexer::HACKISH) {
        setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["hackish"]);
     }
     else if(type == Python3Lexer::SPECIAL) {
        setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["special"]);
     }
     else if(type == Python3Lexer::BUG) {
         setFormat(startIndex, stopIndex - startIndex + 1, basicStyles["bugs"]);
     }
    }

}

std::vector<CustomToken> ANTLRSyntaxHighlighter::getTokens(const QString text) {
    std::string inputText = text.toUtf8().data();
    ANTLRInputStream input(inputText);
    // Create a lexer which scans the input stream to create a token stream.
    Python3Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    // list of custom token
    vector<CustomToken> tokensList;
    // tokens.getTokens() gives list of `Token`
    for (Token *token : tokens.getTokens()) {
        tokensList.push_back(CustomToken(token->getType(), token->getStartIndex(), token->getStopIndex(), token->getLine(), token->getText().data()));
    }
    return tokensList;
}

void ANTLRSyntaxHighlighter::SetSearchRegEx(const QString &text) {
    mSearchRegex = text;
}

const QTextCharFormat
ANTLRSyntaxHighlighter::getTextCharFormat(const QString &colorName,
        const QString &style,
        const QString &backColorName) {
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
    if (style.contains("underline", Qt::CaseInsensitive))
        charFormat.setFontUnderline(true);
    return charFormat;
}
