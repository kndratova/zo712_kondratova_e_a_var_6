#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButtonConfirm, &QPushButton::clicked, this, &Widget::confirmInitialInput);
    connect(ui->pushButtonTest, &QPushButton::clicked, this, &Widget::testMethod);
    connect(ui->pushButtonScale, &QPushButton::clicked, this, &Widget::scaleTriangle);
    connect(ui->pushButtonReset, &QPushButton::clicked, this, &Widget::reset);
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &Widget::exit);

    ui->doubleSpinBoxScale->setMinimum(1);
    ui->doubleSpinBoxScale->setSingleStep(0.5);

    reset();
}

void Widget::confirmInitialInput() {

    double side1 = ui->lineEditTriangleSide_1->text().toDouble();
    double side2 = ui->lineEditTriangleSide_2->text().toDouble();
    double angle = ui->lineEditTriangleAngle_12->text().toDouble();

    if (side1 > 0 && side2 > 0 && angle > 0) {
        triangle = Triangle(side1, side2, angle);
        ui->groupBoxInitialInput->setEnabled(false);
        ui->groupBoxTesting->setEnabled(true);
    }
}

void Widget::testMethod() {
    QString selectedMethod = ui->comboBoxTestingMethod->currentText();
    QString resultData = "";

    if (selectedMethod == "get type") {
        resultData = "Triangle Type: " + triangle.GetType();
    } else if (selectedMethod == "get perimeter") {
        resultData = "Perimeter: " + QString::number(triangle.GetPerimeter());
    } else if (selectedMethod == "get all angles") {
        double* angles = triangle.GetAllAngles();
        QString anglesString = "All Angles: \n";

        for (int i = 0; i < 3; ++i) {
            anglesString += QString::number(i + 1) + ": " + QString::number(angles[i]) + "\n";
        }
        delete[] angles;

        resultData = anglesString;
    } else if (selectedMethod == "get max angle height") {
        resultData = "Max Angle Height: " + QString::number(triangle.GetMaxAngleHeight());
    } else {
        resultData = "Invalid testing method";
        qDebug() << resultData;
    }

    ui->textBrowserResultData->setText(resultData);
}


void Widget::scaleTriangle() {
    double scaler = ui->doubleSpinBoxScale->value();
    triangle *= scaler;
    testMethod();
}

void Widget::reset() const {
    ui->groupBoxInitialInput->setEnabled(true);
    ui->groupBoxTesting->setEnabled(false);
    ui->lineEditTriangleAngle_12->clear();
    ui->lineEditTriangleSide_1->clear();
    ui->lineEditTriangleSide_2->clear();
    ui->textBrowserResultData->clear();
    ui->comboBoxTestingMethod->setCurrentIndex(0);
}

void Widget::exit() const {
    QApplication::quit();
}

Widget::~Widget()
{
    delete ui;
}



