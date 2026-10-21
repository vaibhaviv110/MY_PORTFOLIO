/*Define an abstract class `Shape` with pure virtual functions `area()` and `draw()`.
 Implement concrete classes `Circle` and `Rectangle` that inherit from `Shape`.
  Demonstrate polymorphism by creating an array of `Shape` pointers pointing to objects of both `Circle` and `Rectangle`.
 Call the `area()` and `draw()` functions for each object*/
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void area() override
    {
        cout << "Area of Circle = " << 3.14 * 5 * 5 << endl;
    }

    void draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area() override
    {
        cout << "Area of Rectangle = " << 10 * 5 << endl;
    }

    void draw() override
    {
        cout << "Drawing Rectangle" << endl;
    }
};

int main()
{
    Circle c;
    Rectangle r;

    Shape *s[2];
    s[0] = &c;
    s[1] = &r;

    for (int i = 0; i < 2; i++)
    {
        s[i]->area();
        s[i]->draw();
    }

    return 0;
}

