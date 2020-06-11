#include "customtoken.h"

CustomToken::CustomToken(int type, int startIndex, int stopIndex, int lineNumber, QString text) :
        type(type), startIndex(startIndex), stopIndex(stopIndex), lineNumber(lineNumber), text(text)
{}

QString CustomToken::getText() {
    return text;
}

int CustomToken::getType() {
    return type;
}

int CustomToken::getStartIndex() {
    return startIndex;
}

int CustomToken::getStopIndex() {
    return stopIndex;
}

int CustomToken::getLineNumber() {
    return lineNumber;
}
