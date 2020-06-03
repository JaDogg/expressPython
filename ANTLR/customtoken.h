#ifndef CUSTOMTOKEN_H
#define CUSTOMTOKEN_H

#include <QString>

class CustomToken
{
private:
    QString text;
    int type;
    int startIndex;
    int stopIndex;
    int lineNumber;
public:
    CustomToken(int type, int startIndex, int stopIndex, int lineNumber, QString text);
    QString getText();
    int getType();
    int getStartIndex();
    int getStopIndex();
    int getLineNumber();
};

#endif // CUSTOMTOKEN_H
