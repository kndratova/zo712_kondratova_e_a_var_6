#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    void confirmInitialInput();
    void testMethod();
    void scaleTriangle();
    void reset() const;
    void exit() const;

    Triangle triangle;
};

#endif // WIDGET_H
