#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include <unordered_map>

#include "basestring.h"
#include "ui_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

private slots:
    void onSetElementsAmount();
    void onRequiredElementIndexChanged();
    void onSetElementInitialValues();
    void onReset();
    void onExit();
    void onTest();
    void updateMethodToTestComboBox();
    void updateOperandToTestComboBox();
    void updateExtraOperand();

private:
    Ui::Widget* ui;
    std::unordered_map<int, int> elementTypeMap;
    BaseString** stringElementsArray;
    BaseString* extraOperand;
    BaseString** operandStrings;
    int stringElementsAmount;

    void initializeTestingBlock();
    void updateClassToTestComboBox();
};

#endif // WIDGET_H
