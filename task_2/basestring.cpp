#include "basestring.h"
#include <cstring>

// инициализация поля счетчика вызовов к.к.
int BaseString::copyConstructorCallsCount = 0;

// конструктор без параметров
BaseString::BaseString()
    : stringData(nullptr) {
    qDebug() << this << "BaseString()" << endl;
}

// конструктор, параметр си строка
BaseString::BaseString(const char* cString)
    : stringData(nullptr) {
    qDebug() << this << "BaseString(const char*)" << endl;

    if (cString) {
        int length = strlen(cString);
        stringData = new char[length + 1];
        stringData[0] = '\0';
        strncat(stringData, cString, length);
    }
}

// конструктор, параметр символ
BaseString::BaseString(char initialChar)
    : stringData(nullptr) {

    qDebug() << this << "BaseString(char)" << endl;

    stringData = new char[2];
    stringData[0] = initialChar;
    stringData[1] = '\0';
}

// конструктор копирования
BaseString::BaseString(const BaseString& other)
    : stringData(nullptr) {
    qDebug() << this << "BaseString(const BaseString&)" << endl;

    copyConstructorCallsCount++;

    if (other.stringData) {
        int length = strlen(other.stringData) + 1;
        stringData = new char[length];
        strncpy(stringData, other.stringData, length);
        stringData[length - 1] = '\0';
    }
}

// перегрузка операции присваивания
BaseString& BaseString::operator=(const BaseString& baseString) {
    qDebug() << this << "operator=" << endl;

    if (this != &baseString) {
        delete[] stringData;

        if (baseString.stringData) {
            int length = strlen(baseString.stringData);
            stringData = new char[length + 1];
            strncpy(stringData, baseString.stringData, length + 1);
        } else {
            stringData = nullptr;
        }
    }
    return *this;
}

// геттер к-ва вызовов к.к.
int BaseString::GetCopyConstructorCallsCount() {
    return copyConstructorCallsCount;
}

// геттер байтовой длины строки
int BaseString::GetByteStringLength() const {
    qDebug() << this << "GetByteStringLength()" << endl;

    if (!stringData) {
        return -1;
    }

    return (strlen(stringData) + 1) * sizeof(char);
}

// геттер байтовой строки
const char* BaseString::GetStringData() const {
    qDebug() << this << "GetStringData()" << endl;

    if (stringData != nullptr) {
        return stringData;
    } else {
        return "";
    }
}

// деструктор
BaseString::~BaseString() {
    qDebug() << this << "~BaseString()" << endl;

    if (stringData) {
        delete[] stringData;
    }
}
