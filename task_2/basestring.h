#ifndef BASESTRING_H
#define BASESTRING_H

#include <QDebug>
#include <cstring>

using namespace Qt;

class BaseString {

public:
    BaseString();

    BaseString(const char* cString);

    BaseString(char initialChar);

    BaseString(const BaseString& other);

    BaseString& operator=(const BaseString& baseString);

    virtual ~BaseString();

    static int GetCopyConstructorCallsCount();

    int GetByteStringLength() const;

    const char* GetStringData() const;

    const int type = 0;

protected:
    char* stringData;

private:
    static int copyConstructorCallsCount;
};

#endif // BASESTRING_H
