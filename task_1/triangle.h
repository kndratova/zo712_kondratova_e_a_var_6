#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>
#include <QString>

class Triangle
{
public:
    Triangle();
    Triangle(const double sideLength_1,
             const double sideLength_2,
             const double angle_12);
    Triangle& operator=(const Triangle& other);
    Triangle(const Triangle& other);
    ~Triangle();

    void SetSidesAndAngle(const double sideLength_1,
                          const double sideLength_2,
                          const double angle_12);


    QString GetType() const;
    double GetPerimeter() const;
    double* GetAllAngles() const;
    double GetMaxAngleHeight() const;

    Triangle& operator*=(double scale);

private:
    double sideLength_1;
    double sideLength_2;
    double angle_12;
};

#endif // TRIANGLE_H
