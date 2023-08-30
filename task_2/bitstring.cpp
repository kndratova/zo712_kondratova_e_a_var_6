#include "bitstring.h"

// инициализация поля счетчика вызовов к.к.
int BitString::copyConstructorCallsCount = 0;

// конструктор без параметров
BitString::BitString()
    : BaseString() {
    qDebug() << this << "BitString()" << endl;
}

// конструктор, параметр си строка
BitString::BitString(const char* cString)
    : BaseString(cString) {
    qDebug() << this << "BitString(const char*)" << endl;

    bool isValid = true;
    int length = strlen(cString);
    for (int i = 0; i < length; ++i) {
        if (cString[i] != '0' && cString[i] != '1') {
            isValid = false;
            qDebug() << "Invalid input: " << cString << endl;
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
BitString::BitString(const BitString& other)
    : BaseString(other) {
    qDebug() << this << "BitString(const BitString&)" << endl;

    copyConstructorCallsCount++;

    if (other.stringData) {
        int length = strlen(other.stringData);
        stringData = new char[length + 1];
        strncpy(stringData, other.stringData, length + 1);
    } else {
        stringData = nullptr;
    }
}

// перегрузка операции присваивания
BitString& BitString::operator=(const BitString& bitString) {
    qDebug() << this << "operator=" << endl;

    if (this != &bitString) {
        delete[] stringData;

        if (bitString.stringData) {
            size_t length = strlen(bitString.stringData);
            stringData = new char[length + 1];
            strncpy(stringData, bitString.stringData, length + 1);
        } else {
            stringData = nullptr;
        }
    }
    return *this;
}

// переопределение проверки на равенство ==
bool BitString::operator==(const BitString& other) const {
    if (stringData && other.stringData) {
        return strcmp(stringData, other.stringData) == 0;
    }
    return false;
}

// переопределение операции сложения
BitString BitString::operator+(const BitString& other) const {
    qDebug() << this << "operator+" << endl;

    if (!stringData || !other.stringData) {
        return BitString();
    }

    int lenA = strlen(stringData);
    int lenB = strlen(other.stringData);

    int maxLen = std::max(lenA, lenB);

    char* operand1 = new char[maxLen + 1];
    char* operand2 = new char[maxLen + 1];

    if (lenA < lenB) {
        strncpy(operand1, other.stringData, maxLen);
        operand1[maxLen] = '\0';

        for (int i = maxLen - 1; i >= 0; i--) {
            int diff = maxLen - 1 - i;
            operand2[i] = (diff < lenA) ? stringData[lenA - 1 - diff] : '0';
        }
    } else {
        strncpy(operand1, stringData, maxLen);
        operand1[maxLen] = '\0';

        for (int i = maxLen - 1; i >= 0; i--) {
            int diff = maxLen - 1 - i;
            operand2[i] = (diff < lenB) ? other.stringData[lenB - 1 - diff] : '0';
        }
    }

    char* resultData = new char[maxLen + 2];
    // for (int i = 0; i < maxLen + 2; ++i) {
    //     resultData[i] = '0';
    // }
    resultData[maxLen + 1] = '\0';

    char carry = '0';

    for (int i = maxLen - 1; i >= 0; --i) {
        if (carry == '0') {
            if (operand1[i] != operand2[i]) {
                resultData[i + 1] = '1';
            } else if (operand1[i] == '0') {
                resultData[i + 1] = '0';
            } else {
                resultData[i + 1] = '0';
                carry = '1';
            }
        } else {
            if (operand1[i] != operand2[i]) {
                resultData[i + 1] = '0';
            } else if (operand1[i] == '0') {
                resultData[i + 1] = '1';
                carry = '0';
            } else {
                resultData[i + 1] = '1';
            }
        }
    }

    resultData[0] = carry;

    BitString result(resultData);

    delete[] operand1;
    delete[] operand2;
    delete[] resultData;

    return result;
}

// геттер строки преобразованной в целое число
int BitString::GetConvertedBitStringToInt() const {
    qDebug() << this << "GetConvertedBitStringToInt()" << endl;

    int value = 0;
    int length = strlen(stringData);

    for (int i = 0; i < length; ++i) {
        value = (value << 1) + (stringData[i] - '0');
    }

    return value;
}

// геттер инвертированной строки
const char* BitString::GetInvertedString() const {
    qDebug() << this << "GetInvertedString()" << endl;

    if (stringData) {
        int length = strlen(stringData);
        char* invertedData = new char[length + 1];
        invertedData[length] = '\0';

        for (int i = 0; i < length; ++i) {
            invertedData[i] = (stringData[i] == '0') ? '1' : '0';
        }

        return invertedData;
    } else {
        return "0";
    }
}

// геттер к-ва вызовов к.к.
int BitString::GetCopyConstructorCallsCount() {
    return copyConstructorCallsCount;
}

// деструктор
BitString::~BitString() {
    qDebug() << this << "~BitString()" << endl;
}
