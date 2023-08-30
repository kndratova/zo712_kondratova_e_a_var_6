#include "triangle.h"
#include <QDebug>
#include <QtCore/qmath.h>

Triangle::Triangle(double side1, double side2, double angle)
    : sideLength_1(side1)
    , sideLength_2(side2)
    , angle_12(angle) {
    qDebug() << "Triangle(double, double, double)";
}

Triangle::Triangle(const Triangle& other)
    : sideLength_1(other.sideLength_1)
    , sideLength_2(other.sideLength_2)
    , angle_12(other.angle_12) {
    qDebug() << "Triangle(const Triangle&)";
}

Triangle::~Triangle() {
    qDebug() << "Destructor";
}

Triangle::Triangle()

    : sideLength_1(0)
    , sideLength_2(0)
    , angle_12(0) {
    qDebug() << "Triangle()";
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        sideLength_1 = other.sideLength_1;
        sideLength_2 = other.sideLength_2;
        angle_12 = other.angle_12;
    }
    return *this;
}

QString Triangle::GetType() const {
    qDebug() << "GetType";

    QString type = "Undefined";
    double* angles = GetAllAngles();

    if (angles[0] == 90 || angles[1] == 90 || angles[2] == 90) {
        type = "Right-angled";
    } else if (angles[0] > 90 || angles[1] > 90 || angles[2] > 90) {
        type = "Obtuse";
    } else {
        type = "Acute";
    }

    delete[] angles;

    return type;
}

double Triangle::GetPerimeter() const {
    qDebug() << "GetPerimeter";

    double perimeter = sideLength_1 + sideLength_2 + sqrt(sideLength_1 * sideLength_1 + sideLength_2 * sideLength_2 - 2 * sideLength_1 * sideLength_2 * cos(qDegreesToRadians(angle_12)));

    return perimeter;
}

double* Triangle::GetAllAngles() const {

    double* allAngles = new double[3];

    allAngles[0] = angle_12;

    double sideLength_3 = qSqrt(sideLength_1 * sideLength_1 + sideLength_2 * sideLength_2 - 2 * sideLength_1 * sideLength_2 * qCos(qDegreesToRadians(angle_12)));
    allAngles[1] = qRadiansToDegrees(qAcos((sideLength_2 * sideLength_2 + sideLength_3 * sideLength_3 - sideLength_1 * sideLength_1) / (2 * sideLength_2 * sideLength_3)));
    allAngles[2] = 180 - allAngles[1] - allAngles[0];

    qDebug() << "GetAllAngles";
    return allAngles;
}

double Triangle::GetMaxAngleHeight() const {
    qDebug() << "GetMinHeight";

    double sideLength_3 = qSqrt(sideLength_1 * sideLength_1 + sideLength_2 * sideLength_2 - 2 * sideLength_1 * sideLength_2 * qCos(qDegreesToRadians(angle_12)));
    double s = GetPerimeter() / 2;
    double area = sqrt(s * (s - sideLength_1) * (s - sideLength_2) * (s - sideLength_3));

    double minHeight = 2 * area / sideLength_3;
    return minHeight;
}

Triangle& Triangle::operator*=(double scale) {
    qDebug() << "Operator *=";

    sideLength_1 *= scale;
    sideLength_2 *= scale;

    return *this;
}
