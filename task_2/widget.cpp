#include "widget.h"
#include "bitstring.h"
#include "identifierstring.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    stringElementsArray = nullptr;
    operandStrings = nullptr;
    extraOperand = nullptr;
    stringElementsAmount = 0;

    connect(ui->pushButtonElementsAmount, &QPushButton::clicked, this, &Widget::onSetElementsAmount);
    connect(ui->spinBoxElementNumber, QOverload<int>::of(&QSpinBox::valueChanged), this, &Widget::onRequiredElementIndexChanged);
    connect(ui->pushButtonSetInitialData, &QPushButton::clicked, this, &Widget::onSetElementInitialValues);
    connect(ui->comboBoxClassToTest, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::updateMethodToTestComboBox);
    connect(ui->comboBoxMethodToTest, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::updateExtraOperand);
    connect(ui->pushButtonReset, &QPushButton::clicked, this, &Widget::onReset);
    connect(ui->pushButtonTestMethod, &QPushButton::clicked, this, &Widget::onTest);
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &Widget::onExit);

    onReset();
}

void Widget::onReset() {

    if (stringElementsArray != nullptr) {
        for (int i = 0; i < stringElementsAmount; ++i) {
            if (stringElementsArray[i] != nullptr) {
                delete stringElementsArray[i];
            }
        }
        delete[] stringElementsArray;
        stringElementsArray = nullptr;
    }

    if (operandStrings != nullptr) {
        delete[] operandStrings;
        operandStrings = nullptr;
    }

    if (extraOperand != nullptr) {
        delete extraOperand;
        extraOperand = nullptr;
    }

    elementTypeMap.clear();
    stringElementsAmount = 0;

    ui->comboBoxClassToTest->clear();
    ui->comboBoxMethodToTest->clear();
    ui->comboBoxOperandToTest->clear();
    ui->lineEditExtraOperandToTest->clear();
    ui->textBrowserTestingInitialData->clear();
    ui->textBrowserTestingResultData->clear();
    ui->comboBoxElementType->clear();
    ui->lineEditInitialValue->clear();
    ui->spinBoxElementNumber->setValue(1);
    ui->spinBoxElementsAmount->setValue(1);

    ui->groupBoxTesting->setEnabled(false);
    ui->groupBoxInitialValues->setEnabled(false);
    ui->groupBoxElementsAmount->setEnabled(true);
}

void Widget::onSetElementsAmount() {
    try {
        stringElementsAmount = ui->spinBoxElementsAmount->value();
        stringElementsArray = new BaseString*[stringElementsAmount];

        for (int i = 0; i < stringElementsAmount; ++i) {
            stringElementsArray[i] = new BaseString("");
            elementTypeMap[i] = 0;
        }

        ui->spinBoxElementNumber->setMinimum(1);
        ui->spinBoxElementNumber->setMaximum(stringElementsAmount);

        ui->comboBoxElementType->addItems({ "String", "Identifier String", "Bit String" });

        ui->groupBoxInitialValues->setEnabled(true);
        ui->groupBoxElementsAmount->setEnabled(false);
    } catch (...) {
        qDebug() << "onSetElementsAmount error";
    }
}

void Widget::onRequiredElementIndexChanged() {
    int previousIndex = ui->spinBoxElementNumber->property("previousValue").toInt();
    int currentIndex = ui->spinBoxElementNumber->value() - 1;

    if (previousIndex >= 0 && previousIndex < stringElementsAmount && previousIndex != currentIndex) {
        try {
            QString initialValue = ui->lineEditInitialValue->text();
            int newElementType = ui->comboBoxElementType->currentIndex();

            delete stringElementsArray[previousIndex];

            switch (newElementType) {
            case 0:
                stringElementsArray[previousIndex] = new BaseString(initialValue.toStdString().c_str());
                elementTypeMap[previousIndex] = 0;
                break;
            case 1:
                stringElementsArray[previousIndex] = new IdentifierString(initialValue.toStdString().c_str());
                elementTypeMap[previousIndex] = 1;
                break;
            case 2:
                stringElementsArray[previousIndex] = new BitString(initialValue.toStdString().c_str());
                elementTypeMap[previousIndex] = 2;
                break;
            default:
                qDebug() << "Unknown element type";
                break;
            }

            ui->lineEditInitialValue->setText(QString::fromStdString(stringElementsArray[currentIndex]->GetStringData()));
            ui->comboBoxElementType->setCurrentIndex(elementTypeMap[currentIndex]);
        } catch (...) {
            qDebug() << "Unable to set element";
        }
    }

    int newIndex = ui->spinBoxElementNumber->value() - 1;
    ui->spinBoxElementNumber->setProperty("previousValue", newIndex);
}

void Widget::onSetElementInitialValues() {
    int currentIndex = ui->spinBoxElementNumber->value() - 1;

    QString initialValue = ui->lineEditInitialValue->text();
    int newElementType = ui->comboBoxElementType->currentIndex();

    delete stringElementsArray[currentIndex];

    switch (newElementType) {
    case 0:
        stringElementsArray[currentIndex] = new BaseString(initialValue.toStdString().c_str());
        elementTypeMap[currentIndex] = 0;
        break;
    case 1:
        stringElementsArray[currentIndex] = new IdentifierString(initialValue.toStdString().c_str());
        elementTypeMap[currentIndex] = 1;
        break;
    case 2:
        stringElementsArray[currentIndex] = new BitString(initialValue.toStdString().c_str());
        elementTypeMap[currentIndex] = 2;
        break;
    default:
        qDebug() << "Unknown element type";
        break;
    }

    qDebug() << "All Elements:";
    for (int i = 0; i < stringElementsAmount; ++i) {
        qDebug() << "Element" << i + 1 << "- Type:" << elementTypeMap[i] << ", Value:" << stringElementsArray[i]->GetStringData();
    }

    ui->comboBoxElementType->clear();
    ui->lineEditInitialValue->clear();
    ui->spinBoxElementNumber->clear();
    ui->groupBoxInitialValues->setEnabled(false);

    initializeTestingBlock();
}

void Widget::initializeTestingBlock() {
    updateClassToTestComboBox();
    updateMethodToTestComboBox();
    updateOperandToTestComboBox();
    updateExtraOperand();
    ui->groupBoxTesting->setEnabled(true);
}

void Widget::updateClassToTestComboBox() {
    ui->comboBoxClassToTest->clear();

    bool hasString = false;
    bool hasIdentifierString = false;
    bool hasBitString = false;

    for (const auto& pair : elementTypeMap) {
        int elementType = pair.second;
        if (elementType == 0) {
            hasString = true;
        } else if (elementType == 1) {
            hasIdentifierString = true;
        } else if (elementType == 2) {
            hasBitString = true;
        }
    }

    if (hasString) {
        ui->comboBoxClassToTest->addItem("String");
    }
    if (hasIdentifierString) {
        ui->comboBoxClassToTest->addItem("Identifier String");
    }
    if (hasBitString) {
        ui->comboBoxClassToTest->addItem("Bit String");
    }
}

void Widget::updateMethodToTestComboBox() {
    ui->comboBoxMethodToTest->clear();

    QString selectedType = ui->comboBoxClassToTest->currentText();

    if (selectedType == "String") {
        QStringList stringMethods = { "get byte length" };
        ui->comboBoxMethodToTest->addItems(stringMethods);
    } else if (selectedType == "Identifier String") {
        QStringList identifierStringMethods = { "get byte length", "find last index of char", "subtract operands", "compare operands" };
        ui->comboBoxMethodToTest->addItems(identifierStringMethods);
    } else if (selectedType == "Bit String") {
        QStringList bitStringMethods = { "get byte length", "invert data", "sum up operands", "compare operands" };
        ui->comboBoxMethodToTest->addItems(bitStringMethods);
    }

    updateOperandToTestComboBox();
    updateExtraOperand();
}

void Widget::updateOperandToTestComboBox() {
    ui->comboBoxOperandToTest->clear();
    if (operandStrings != nullptr) {
        delete[] operandStrings;
    }

    QString selectedType = ui->comboBoxClassToTest->currentText();

    int operandCount = 0;
    for (int i = 0; i < stringElementsAmount; ++i) {
        int elementType = elementTypeMap[i];
        QString elementTypeString;

        if (elementType == 0) {
            elementTypeString = "String";
        } else if (elementType == 1) {
            elementTypeString = "Identifier String";
        } else if (elementType == 2) {
            elementTypeString = "Bit String";
        }

        if (elementTypeString == selectedType) {
            operandCount++;
        }
    }

    operandStrings = new BaseString*[operandCount];
    int operandIndex = 0;
    for (int i = 0; i < stringElementsAmount; ++i) {
        int elementType = elementTypeMap[i];
        QString elementTypeString;

        if (elementType == 0) {
            elementTypeString = "String";
        } else if (elementType == 1) {
            elementTypeString = "Identifier String";
        } else if (elementType == 2) {
            elementTypeString = "Bit String";
        }

        if (elementTypeString == selectedType) {
            operandStrings[operandIndex] = stringElementsArray[i];
            operandIndex++;

            QString elementString = QString::fromStdString(stringElementsArray[i]->GetStringData());
            ui->comboBoxOperandToTest->addItem(elementString);
        }
    }
}

void Widget::updateExtraOperand() {
    ui->lineEditExtraOperandToTest->setText("");
    ui->lineEditExtraOperandToTest->setEnabled(false);
    QString selectedMethod = ui->comboBoxMethodToTest->currentText();

    if (selectedMethod == "find last index of char"
        || selectedMethod == "subtract operands"
        || selectedMethod == "sum up operands"
        || selectedMethod == "compare operands") {
        ui->lineEditExtraOperandToTest->setEnabled(true);
    }
}

void Widget::onTest() {
    QString selectedMethod = ui->comboBoxMethodToTest->currentText();
    QString selectedClass = ui->comboBoxClassToTest->currentText();
    QString extraOperandText = ui->lineEditExtraOperandToTest->text();

    qDebug() << "Selected Method: " << selectedMethod;
    qDebug() << "Selected Class: " << selectedClass;
    qDebug() << "Extra Operand: " << extraOperandText;

    QString resultData = "Result: ";

    if (selectedClass == "String") {
        BaseString* initialOperand = static_cast<BaseString*>(operandStrings[ui->comboBoxOperandToTest->currentIndex()]);
        if (selectedMethod == "get byte length") {
            int byteLength = initialOperand->GetByteStringLength();
            resultData += "Byte Length: " + QString::number(byteLength);
        }
    } else if (selectedClass == "Identifier String") {
        IdentifierString* initialOperand = static_cast<IdentifierString*>(operandStrings[ui->comboBoxOperandToTest->currentIndex()]);
        if (selectedMethod == "get byte length") {
            int byteLength = initialOperand->GetByteStringLength();
            resultData += "Byte Length: " + QString::number(byteLength);
        } else if (selectedMethod == "find last index of char") {
            int lastIndex = initialOperand->GetLastIndexOfChar(extraOperandText[0].toLatin1());
            resultData += "Last Index of '" + extraOperandText + "': " + QString::number(lastIndex);
        } else if (selectedMethod == "subtract operands") {
            IdentifierString* extraOperand = new IdentifierString(extraOperandText.toStdString().c_str());
            IdentifierString result = *initialOperand - *extraOperand;
            resultData += "Subtraction Result: " + QString::fromStdString(result.GetStringData());
            delete extraOperand;
        } else if (selectedMethod == "compare operands") {
            IdentifierString* extraOperand = new IdentifierString(extraOperandText.toStdString().c_str());
            bool isEqual = (*extraOperand == *initialOperand);
            QString result = isEqual ? "TRUE" : "FALSE";
            resultData += "Compare Result: " + result;
            delete extraOperand;
        }

    } else if (selectedClass == "Bit String") {
        BitString* initialOperand = static_cast<BitString*>(operandStrings[ui->comboBoxOperandToTest->currentIndex()]);
        if (selectedMethod == "get byte length") {
            int byteLength = initialOperand->GetByteStringLength();
            resultData += "Byte Length: " + QString::number(byteLength);
        } else if (selectedMethod == "invert data") {
            BitString invertedResult = initialOperand->GetInvertedString();
            resultData += "Inverted String: " + QString::fromStdString(invertedResult.GetStringData());
        } else if (selectedMethod == "sum up operands") {
            BitString* extraOperand = new BitString(extraOperandText.toStdString().c_str());
            BitString sumResult = *initialOperand + *extraOperand;
            resultData += "Sum Result: " + QString::fromStdString(sumResult.GetStringData());
            delete extraOperand;
        } else if (selectedMethod == "compare operands") {
            BitString* extraOperand = new BitString(extraOperandText.toStdString().c_str());
            bool isEqual = (*extraOperand == *initialOperand);
            QString result = isEqual ? "TRUE" : "FALSE";
            resultData += "Compare Result: " + result;
            delete extraOperand;
        }
    } else {
        resultData = "No such class to test";
    }

    ui->textBrowserTestingResultData->setText(resultData);

    QString initialData = "Initial Data:\n";
    initialData += "Selected Class: " + selectedClass + "\n";
    initialData += "Selected Method: " + selectedMethod + "\n";
    initialData += "Selected Operand: " + ui->comboBoxOperandToTest->currentText() + "\n";
    if (!extraOperandText.isEmpty()) {
        initialData += "Extra Operand: " + extraOperandText + "\n";
    }
    ui->textBrowserTestingInitialData->setText(initialData);
}

Widget::~Widget() {
    qDebug() << "~Widget()" << endl;

    if (stringElementsArray != nullptr) {
        for (int i = 0; i < stringElementsAmount; ++i) {
            if (stringElementsArray[i] != nullptr) {
                delete stringElementsArray[i];
            }
        }
        delete[] stringElementsArray;
    }

    if (operandStrings != nullptr) {
        delete[] operandStrings;
    }

    if (extraOperand != nullptr) {
        delete extraOperand;
    }

    delete ui;
}

void Widget::onExit() {
    QApplication::quit();
}
