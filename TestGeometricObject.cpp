#include "GeometricObject.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

void displayGeometricObject(const GeometricObject& g)
{
    cout << "The area is " << g.getArea() << endl;
    cout << "The perimeter is " << g.getPerimeter() << endl;
}

int main()
{
    Circle circle(5);
    Rectangle rectangle(5, 3);

    cout << "Circle info: " << endl;
    displayGeometricObject(circle);
    cout << "\nRectangle info: " << endl;
    displayGeometricObject(rectangle);
    return 0;
}