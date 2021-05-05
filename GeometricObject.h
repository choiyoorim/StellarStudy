#pragma once
#ifndef GEOMETRICOBJECT_H
#define	GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject {
public:
	GeometricObject();
	GeometricObject(const string& color);
	string getColor() const;
	void setColor(const string& color);
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

private:
	string color;
};
#endif // !GEOMETRICOBJECT_H
