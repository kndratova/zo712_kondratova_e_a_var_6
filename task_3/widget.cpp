#include "widget.h"
#include "ui_widget.h"
#include "widget.h"

#include <QFile>
#include <QFileDialog>

template <typename T>
T calculatePositiveSum(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

QRegularExpression Widget::separator("[\n ]");

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , uintDeque_linkedList()
    , charDeque_linkedList()
    , uintDeque_vector()
    , charDeque_vector() {
    ui->setupUi(this);

    connect(ui->pushButtonLoadFile, &QPushButton::clicked, this, &Widget::loadFile);
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &Widget::exit);
    connect(ui->pushButtonConfirm, &QPushButton::clicked, this, &Widget::confirmData);
    connect(ui->pushButtonPush, &QPushButton::clicked, this, &Widget::pushDeque);
    connect(ui->pushButtonPop, &QPushButton::clicked, this, &Widget::popDeque);
    connect(ui->checkBoxTestIngOption, &QCheckBox::stateChanged, this, &Widget::onTestingOptionChanged);

    ui->frameFunctionTesting->setEnabled(false);
    ui->frameClassTesting->setEnabled(false);
}

void Widget::loadFile() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            ui->textEditLoadedData->setPlainText(fileContent);
        } else {
            qDebug() << "Failed to open file";
        }
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::onTestingOptionChanged() {
    bool option = ui->checkBoxTestIngOption->isChecked();
    if (option == true) {
        ui->comboBoxStorageStructure->setEnabled(false);
        ui->comboBoxStorageStructure->clear();
        ui->comboBoxElementType->clear();
        ui->comboBoxElementType->addItem("int");
        ui->comboBoxElementType->addItem("unsigned int");
        ui->comboBoxElementType->addItem("short");
        ui->comboBoxElementType->addItem("unsigned short");
        ui->comboBoxElementType->addItem("long");
        ui->comboBoxElementType->addItem("unsigned long");
        ui->comboBoxElementType->addItem("long long");
        ui->comboBoxElementType->addItem("unsigned long long");
        ui->comboBoxElementType->addItem("float");
        ui->comboBoxElementType->addItem("double");
        ui->comboBoxElementType->addItem("long double");
    } else {
        ui->comboBoxStorageStructure->addItem("linked list");
        ui->comboBoxStorageStructure->addItem("vector");
        ui->comboBoxStorageStructure->setEnabled(true);
        ui->comboBoxElementType->clear();
        ui->comboBoxElementType->addItem("char");
        ui->comboBoxElementType->addItem("unsigned int");
    }
}

void Widget::confirmData() {

    QString elementType = ui->comboBoxElementType->currentText();
    QStringList lines = ui->textEditLoadedData->toPlainText().split(separator, Qt::SkipEmptyParts);
    bool testingOption = ui->checkBoxTestIngOption->isChecked();

    dataString = "";
    ui->textBrowserInitialData->setText("");
    ui->textBrowserPositiveSum->setText("");

    uintDeque_linkedList.clear();
    charDeque_linkedList.clear();
    uintDeque_vector.clear();
    charDeque_vector.clear();

    if (testingOption == true) {
        ui->frameFunctionTesting->setEnabled(true);
        ui->frameClassTesting->setEnabled(false);
        if (elementType == "int") {
            Deque_linkedList<int> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                int value = line.toInt(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            int* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "unsigned int") {
            Deque_linkedList<unsigned int> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned int value = line.toUInt(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            unsigned int* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "short") {
            Deque_linkedList<short> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                short value = line.toShort(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            short* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "unsigned short") {
            Deque_linkedList<unsigned short> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned short value = line.toUShort(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            unsigned short* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "long") {
            Deque_linkedList<long> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                long value = line.toLong(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            long* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "unsigned long") {
            Deque_linkedList<unsigned long> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned long value = line.toULong(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            unsigned long* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "long long") {
            Deque_linkedList<long long> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                long long value = line.toLongLong(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            long long* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "unsigned long long") {
            Deque_linkedList<unsigned long long> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned long long value = line.toULongLong(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            unsigned long long* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size())));
            delete[] dequeArray;

        } else if (elementType == "float") {
            Deque_linkedList<float> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                float value = line.toFloat(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            float* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size()), 'f', 2));
            delete[] dequeArray;

        } else if (elementType == "double") {
            Deque_linkedList<double> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                double value = line.toDouble(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            double* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(calculatePositiveSum(dequeArray, deque.size()), 'd', 2));
            delete[] dequeArray;

        } else if (elementType == "long double") {
            Deque_linkedList<long double> deque;
            for (const QString& line : lines) {
                bool conversionOk;
                QString valueStr = line;
                long double value = valueStr.toDouble(&conversionOk);
                if (conversionOk) {
                    deque.pushBack(value);
                }
            }

            ui->textBrowserInitialData->setText(QString::fromStdString(deque.toString()));

            long double* dequeArray = deque.toArray();
            ui->textBrowserPositiveSum->setText(QString::number(static_cast<double>(calculatePositiveSum(dequeArray, deque.size())), 'd', 2));
            delete[] dequeArray;

        } else {
            qDebug() << "invalid element type";
        }
        // зато есть из чего выбрать.

    } else {
        ui->frameFunctionTesting->setEnabled(false);
        ui->frameClassTesting->setEnabled(true);

        QString storageStructure = ui->comboBoxStorageStructure->currentText();
        if (storageStructure == "linked list") {
            if (elementType == "unsigned int") {

                for (const QString& line : lines) {
                    bool conversionOk;
                    unsigned int value = line.toUInt(&conversionOk);
                    if (conversionOk) {
                        uintDeque_linkedList.pushBack(value);
                    }
                }

                dataVariant = DataVariant::UINT_LINKEDLIST;
                ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_linkedList.toString()));

            } else if (elementType == "char") {

                for (const QString& line : lines) {
                    if (line.size() == 1) {
                        char value = line.at(0).toLatin1();
                        if (value) {
                            charDeque_linkedList.pushBack(value);
                        }
                    }
                }

                dataVariant = DataVariant::CHAR_LINKEDLIST;
                ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_linkedList.toString()));
            } else {
                qDebug() << "invalid element type";
            }
        } else if (storageStructure == "vector") {
            if (elementType == "unsigned int") {

                for (const QString& line : lines) {
                    bool conversionOk;
                    unsigned int value = line.toUInt(&conversionOk);

                    if (conversionOk) {
                        uintDeque_vector.pushBack(value);
                    }
                }

                dataVariant = DataVariant::UINT_VECTOR;
                ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_vector.toString()));
            } else if (elementType == "char") {

                for (const QString& line : lines) {
                    if (line.size() == 1) {
                        char value = line.at(0).toLatin1();
                        if (value) {
                            charDeque_vector.pushBack(value);
                        }
                    }
                }

                dataVariant = DataVariant::CHAR_VECTOR;
                ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_vector.toString()));
            } else {

                qDebug() << "invalid element type";
            }
        } else {
            qDebug() << "invalid storage structure";
        }
    }

    qDebug() << "uintDeque_linkedList " << uintDeque_linkedList.toString();
    qDebug() << "charDeque_linkedList " << charDeque_linkedList.toString();
    qDebug() << "uintDeque_vector " << uintDeque_vector.toString();
    qDebug() << "charDeque_vector " << charDeque_vector.toString();
}

void Widget::exit() {

    QApplication::quit();
}

void Widget::popDeque() {
    QString popType = ui->comboBoxPop->currentText();

    if (popType == "pop front") {

        if (dataVariant == DataVariant::UINT_LINKEDLIST && uintDeque_linkedList.size() > 0) {
            uintDeque_linkedList.popFront();
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_linkedList.toString()));

        } else if (dataVariant == DataVariant::CHAR_LINKEDLIST && charDeque_linkedList.size() > 0) {

            charDeque_linkedList.popFront();
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_linkedList.toString()));

        } else if (dataVariant == DataVariant::UINT_VECTOR && uintDeque_vector.size() > 0) {

            uintDeque_vector.popFront();
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_vector.toString()));

        } else if (dataVariant == DataVariant::CHAR_VECTOR && charDeque_vector.size() > 0) {

            charDeque_vector.popFront();
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_vector.toString()));

        } else {
            qDebug() << "unable to pop";
        }

    } else if (popType == "pop back") {

        if (dataVariant == DataVariant::UINT_LINKEDLIST && uintDeque_linkedList.size() > 0) {
            uintDeque_linkedList.popBack();
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_linkedList.toString()));

        } else if (dataVariant == DataVariant::CHAR_LINKEDLIST && charDeque_linkedList.size() > 0) {

            charDeque_linkedList.popBack();
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_linkedList.toString()));

        } else if (dataVariant == DataVariant::UINT_VECTOR && uintDeque_vector.size() > 0) {

            uintDeque_vector.popBack();
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_vector.toString()));

        } else if (dataVariant == DataVariant::CHAR_VECTOR && charDeque_vector.size() > 0) {

            charDeque_vector.popBack();
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_vector.toString()));

        } else {
            qDebug() << "unable to pop";
        }
    } else {
        qDebug() << "unable to pop";
    }
}

void Widget::pushDeque() {
    QString pushType = ui->comboBoxPush->currentText();
    QStringList lines = ui->lineEditPushData->text().split(separator, Qt::SkipEmptyParts);

    if (pushType == "push front") {
        if (dataVariant == DataVariant::UINT_LINKEDLIST) {
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned int value = line.toUInt(&conversionOk);
                if (conversionOk) {
                    uintDeque_linkedList.pushFront(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_linkedList.toString()));
        } else if (dataVariant == DataVariant::CHAR_LINKEDLIST) {
            for (const QString& line : lines) {
                if (line.size() == 1) {
                    char value = line.at(0).toLatin1();
                    charDeque_linkedList.pushFront(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_linkedList.toString()));
        } else if (dataVariant == DataVariant::UINT_VECTOR) {
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned int value = line.toUInt(&conversionOk);
                if (conversionOk) {
                    uintDeque_vector.pushFront(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_vector.toString()));
        } else if (dataVariant == DataVariant::CHAR_VECTOR) {
            for (const QString& line : lines) {
                if (line.size() == 1) {
                    char value = line.at(0).toLatin1();
                    charDeque_vector.pushFront(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_vector.toString()));
        } else {
            qDebug() << "unable to push";
        }

    } else if (pushType == "push back") {
        if (dataVariant == DataVariant::UINT_LINKEDLIST) {
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned int value = line.toUInt(&conversionOk);
                if (conversionOk) {
                    uintDeque_linkedList.pushBack(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_linkedList.toString()));
        } else if (dataVariant == DataVariant::CHAR_LINKEDLIST) {
            for (const QString& line : lines) {
                if (line.size() == 1) {
                    char value = line.at(0).toLatin1();
                    if (value) {
                        charDeque_linkedList.pushBack(value);
                    }
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_linkedList.toString()));
        } else if (dataVariant == DataVariant::UINT_VECTOR) {
            for (const QString& line : lines) {
                bool conversionOk;
                unsigned int value = line.toUInt(&conversionOk);
                if (conversionOk) {
                    uintDeque_vector.pushBack(value);
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(uintDeque_vector.toString()));
        } else if (dataVariant == DataVariant::CHAR_VECTOR) {
            for (const QString& line : lines) {
                if (line.size() == 1) {
                    char value = line.at(0).toLatin1();
                    if (value) {
                        charDeque_vector.pushBack(value);
                    }
                }
            }
            ui->textBrowserInitialData->setText(QString::fromStdString(charDeque_vector.toString()));
        } else {
            qDebug() << "unable to push";
        }
    } else {
        qDebug() << "unable to push";
    }

    ui->lineEditPushData->setText("");
}
