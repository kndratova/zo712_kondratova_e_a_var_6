/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFormLayout *formLayout_3;
    QGroupBox *groupBoxElementsAmount;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpinBox *spinBoxElementsAmount;
    QPushButton *pushButtonElementsAmount;
    QGroupBox *groupBoxInitialValues;
    QFormLayout *formLayout_2;
    QSpinBox *spinBoxElementNumber;
    QLineEdit *lineEditInitialValue;
    QComboBox *comboBoxElementType;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSetInitialData;
    QLabel *label_3;
    QGroupBox *groupBoxTesting;
    QGridLayout *gridLayout;
    QComboBox *comboBoxOperandToTest;
    QLineEdit *lineEditExtraOperandToTest;
    QTextBrowser *textBrowserTestingResultData;
    QComboBox *comboBoxMethodToTest;
    QComboBox *comboBoxClassToTest;
    QPushButton *pushButtonTestMethod;
    QTextBrowser *textBrowserTestingInitialData;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonExit;
    QLabel *label_4;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(350, 491);
        formLayout_3 = new QFormLayout(Widget);
        formLayout_3->setObjectName("formLayout_3");
        groupBoxElementsAmount = new QGroupBox(Widget);
        groupBoxElementsAmount->setObjectName("groupBoxElementsAmount");
        groupBoxElementsAmount->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(groupBoxElementsAmount);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(groupBoxElementsAmount);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        spinBoxElementsAmount = new QSpinBox(groupBoxElementsAmount);
        spinBoxElementsAmount->setObjectName("spinBoxElementsAmount");
        spinBoxElementsAmount->setMinimum(1);
        spinBoxElementsAmount->setMaximum(9);

        verticalLayout_2->addWidget(spinBoxElementsAmount);

        pushButtonElementsAmount = new QPushButton(groupBoxElementsAmount);
        pushButtonElementsAmount->setObjectName("pushButtonElementsAmount");

        verticalLayout_2->addWidget(pushButtonElementsAmount);


        formLayout_3->setWidget(2, QFormLayout::LabelRole, groupBoxElementsAmount);

        groupBoxInitialValues = new QGroupBox(Widget);
        groupBoxInitialValues->setObjectName("groupBoxInitialValues");
        formLayout_2 = new QFormLayout(groupBoxInitialValues);
        formLayout_2->setObjectName("formLayout_2");
        spinBoxElementNumber = new QSpinBox(groupBoxInitialValues);
        spinBoxElementNumber->setObjectName("spinBoxElementNumber");
        spinBoxElementNumber->setMinimum(1);
        spinBoxElementNumber->setValue(1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, spinBoxElementNumber);

        lineEditInitialValue = new QLineEdit(groupBoxInitialValues);
        lineEditInitialValue->setObjectName("lineEditInitialValue");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditInitialValue);

        comboBoxElementType = new QComboBox(groupBoxInitialValues);
        comboBoxElementType->addItem(QString());
        comboBoxElementType->addItem(QString());
        comboBoxElementType->addItem(QString());
        comboBoxElementType->setObjectName("comboBoxElementType");

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, comboBoxElementType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(2, QFormLayout::LabelRole, horizontalSpacer);

        pushButtonSetInitialData = new QPushButton(groupBoxInitialValues);
        pushButtonSetInitialData->setObjectName("pushButtonSetInitialData");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButtonSetInitialData);


        formLayout_3->setWidget(2, QFormLayout::FieldRole, groupBoxInitialValues);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_3);

        groupBoxTesting = new QGroupBox(Widget);
        groupBoxTesting->setObjectName("groupBoxTesting");
        gridLayout = new QGridLayout(groupBoxTesting);
        gridLayout->setObjectName("gridLayout");
        comboBoxOperandToTest = new QComboBox(groupBoxTesting);
        comboBoxOperandToTest->setObjectName("comboBoxOperandToTest");

        gridLayout->addWidget(comboBoxOperandToTest, 3, 0, 1, 1);

        lineEditExtraOperandToTest = new QLineEdit(groupBoxTesting);
        lineEditExtraOperandToTest->setObjectName("lineEditExtraOperandToTest");

        gridLayout->addWidget(lineEditExtraOperandToTest, 4, 0, 1, 1);

        textBrowserTestingResultData = new QTextBrowser(groupBoxTesting);
        textBrowserTestingResultData->setObjectName("textBrowserTestingResultData");

        gridLayout->addWidget(textBrowserTestingResultData, 6, 0, 1, 3);

        comboBoxMethodToTest = new QComboBox(groupBoxTesting);
        comboBoxMethodToTest->setObjectName("comboBoxMethodToTest");
        comboBoxMethodToTest->setMinimumSize(QSize(130, 0));

        gridLayout->addWidget(comboBoxMethodToTest, 3, 1, 1, 2);

        comboBoxClassToTest = new QComboBox(groupBoxTesting);
        comboBoxClassToTest->addItem(QString());
        comboBoxClassToTest->addItem(QString());
        comboBoxClassToTest->addItem(QString());
        comboBoxClassToTest->setObjectName("comboBoxClassToTest");

        gridLayout->addWidget(comboBoxClassToTest, 0, 0, 1, 3);

        pushButtonTestMethod = new QPushButton(groupBoxTesting);
        pushButtonTestMethod->setObjectName("pushButtonTestMethod");

        gridLayout->addWidget(pushButtonTestMethod, 4, 2, 1, 1);

        textBrowserTestingInitialData = new QTextBrowser(groupBoxTesting);
        textBrowserTestingInitialData->setObjectName("textBrowserTestingInitialData");

        gridLayout->addWidget(textBrowserTestingInitialData, 5, 0, 1, 3);


        formLayout_3->setWidget(4, QFormLayout::SpanningRole, groupBoxTesting);

        pushButtonReset = new QPushButton(Widget);
        pushButtonReset->setObjectName("pushButtonReset");

        formLayout_3->setWidget(8, QFormLayout::LabelRole, pushButtonReset);

        pushButtonExit = new QPushButton(Widget);
        pushButtonExit->setObjectName("pushButtonExit");

        formLayout_3->setWidget(8, QFormLayout::FieldRole, pushButtonExit);

        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_4);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBoxElementsAmount->setTitle(QString());
        label->setText(QCoreApplication::translate("Widget", "Amount:", nullptr));
        pushButtonElementsAmount->setText(QCoreApplication::translate("Widget", "Set", nullptr));
        groupBoxInitialValues->setTitle(QString());
        comboBoxElementType->setItemText(0, QCoreApplication::translate("Widget", "String", nullptr));
        comboBoxElementType->setItemText(1, QCoreApplication::translate("Widget", "Identifier String", nullptr));
        comboBoxElementType->setItemText(2, QCoreApplication::translate("Widget", "Bit String", nullptr));

        pushButtonSetInitialData->setText(QCoreApplication::translate("Widget", "Confirm All", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "TESTING", nullptr));
        groupBoxTesting->setTitle(QString());
        comboBoxClassToTest->setItemText(0, QCoreApplication::translate("Widget", "String", nullptr));
        comboBoxClassToTest->setItemText(1, QCoreApplication::translate("Widget", "Identifier String", nullptr));
        comboBoxClassToTest->setItemText(2, QCoreApplication::translate("Widget", "Bit String", nullptr));

        pushButtonTestMethod->setText(QCoreApplication::translate("Widget", "Test", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("Widget", "Reset", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "by kndratova", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "INITIALIZATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
