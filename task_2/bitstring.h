#ifndef BITSTRING_H
#define BITSTRING_H

#include "basestring.h"

#include <QDebug>
#include <cstring>

using namespace Qt;
class BitString : public BaseString {
public:
    BitString();

    BitString(const char* cString);

    BitString(const BitString& other);

    BitString& operator=(const BitString& bitString);

    bool operator==(const BitString& other) const;

    BitString operator+(const BitString& other) const;

    ~BitString();

    int GetConvertedBitStringToInt() const;

    static int GetCopyConstructorCallsCount();

    const char* GetInvertedString() const;

    const int type = 2;

private:
    static int copyConstructorCallsCount;

    //    char* stringData;
};

#endif // BITSTRING_H
