#include "identifierstring.h"

// инициализация поля счетчика вызовов к.к.
int IdentifierString::copyConstructorCallsCount = 0;

// конструктор без параметров
IdentifierString::IdentifierString()
    : BaseString() {
    qDebug() << this << "IdentifierString()" << endl;
}

// конструктор, параметр си строка
IdentifierString::IdentifierString(const char* cString)
    : BaseString(cString) {
    qDebug() << this << "IdentifierString(const char* cString)" << endl;

    bool isValid = true;
    int length = strlen(cString);
    for (int i = 0; i < length; ++i) {
        if (!(std::isalpha(cString[i]) || cString[i] == '_' || (i > 0 && std::isdigit(cString[i])))) {
            isValid = false;
            break;
        }
    }

    if (isValid) {
        stringData = new char[length + 1];
        stringData[0] = '\0';
        strncat(stringData, cString, length);
    } else {
        stringData = new char[1];
        stringData[0] = '\0';
    }
}

// конструктор копирования
IdentifierString::IdentifierString(const IdentifierString& other)
    : BaseString(other) {
    qDebug() << this << "IdentifierString(const BitString&)" << endl;

    copyConstructorCallsCount++;

    if (other.stringData) {
        size_t length = strlen(other.stringData);
        stringData = new char[length + 1];
        strncpy(stringData, other.stringData, length + 1);
    } else {
        stringData = nullptr;
    }
}

// перегрузка операции присваивания
IdentifierString& IdentifierString::operator=(const IdentifierString& identifierString) {
    qDebug() << this << "operator=" << endl;

    if (this != &identifierString) {
        delete[] stringData;

        if (identifierString.stringData) {
            size_t length = strlen(identifierString.stringData);
            stringData = new char[length + 1];
            strncpy(stringData, identifierString.stringData, length + 1);
        } else {
            stringData = nullptr;
        }
    }
    return *this;
}

// переопределение операции проверки на равенство ==
bool IdentifierString::operator==(const IdentifierString& other) const {
    if (stringData && other.stringData) {
        return strcmp(stringData, other.stringData) == 0;
    }
    return false;
}

// переопределение операции вычитания
IdentifierString IdentifierString::operator-(const IdentifierString& other) const {
    qDebug() << this << "operator-" << endl;

    if (!stringData || !other.stringData) {
        return IdentifierString();
    }

    int length = strlen(stringData);
    char* resultData = new char[length + 1];
    int resultLength = 0;

    for (int i = 0; i < length; ++i) {
        if (strchr(other.stringData, stringData[i]) == nullptr) {
            resultData[resultLength++] = stringData[i];
        }
    }
    resultData[resultLength] = '\0';

    IdentifierString result(resultData);
    delete[] resultData;
    return result;
}

// геттер последнего вхождения символа в строку
int IdentifierString::GetLastIndexOfChar(char charToFind) const {
    qDebug() << this << "GetLastIndexOfChar()" << endl;

    if (!stringData)
        return -1;

    int length = strlen(stringData);
    for (int i = length - 1; i >= 0; --i) {
        if (stringData[i] == charToFind)
            return i;
    }
    return -1;
}

// геттер к-ва вызовов к.к.
int IdentifierString::GetCopyConstructorCallsCount() {

    return copyConstructorCallsCount;
}

// деструктор
IdentifierString::~IdentifierString() {
    qDebug() << this << "~IdentifierString()" << endl;
}
