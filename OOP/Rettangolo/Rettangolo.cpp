// Basic exemple of OOP problem, create a rectangle and calculate its area and perimeter
//
#include <iostream>
using namespace std;

class Rectangle {
    double base, height;
public:
    Rectangle(double b, double h) { this->base = b; this->height = h; }
    void setData(double b, double h) { this->base = b; this->height = h; }
    void getData() { cout << "Base: "<<this->base << endl; cout <<"Height: "<<this->height << endl; }
    double area();
    double perimeter();
};

double Rectangle::area()
{
    return this->base * this->height;
}

double Rectangle::perimeter()
{
    return 2.0*this->base + 2.0 *this->height;
}


int main()
{
    double p, a;
    Rectangle R1(4.3, 5.4);
    R1.getData();
    p = R1.perimeter();
    a = R1.area();
    cout <<"Perimeter: "<< p<< endl;
    cout << "Area: " << a << endl;
    R1.setData(9.7, 10.4);
    p = R1.perimeter();
    a = R1.area();
    cout << "Perimeter: " << p << endl;
    cout << "Area: " << a << endl;
}
