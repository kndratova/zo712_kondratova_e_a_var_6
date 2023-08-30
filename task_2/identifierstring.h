#ifndef IDENTIFIERSTRING_H
#define IDENTIFIERSTRING_H

#include "basestring.h"
#include <QDebug>
#include <QString>
using namespace Qt;

class IdentifierString : public BaseString {
public:
    IdentifierString();

    IdentifierString(const char* cString);

    IdentifierString(const IdentifierString& other);

    IdentifierString& operator=(const IdentifierString& identifierString);

    bool operator==(const IdentifierString& other) const;

    IdentifierString operator-(const IdentifierString& other) const;

    ~IdentifierString();

    static int GetCopyConstructorCallsCount();

    int GetLastIndexOfChar(char charToFind) const;

    const int type = 1;

private:
    static int copyConstructorCallsCount;

    //    char* stringData;
};

#endif // IDENTIFIERSTRING_H
