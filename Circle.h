#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle : public GeometricObject {
public:
	Circle();
	Circle(double);
	Circle(double radius, const string& color);
	double getRadius() const;
	void setRadius(double);
	double getArea() const;
	double getPerimeter() const;
private:
	double radius;
};
#endif // !CIRCLE_H
