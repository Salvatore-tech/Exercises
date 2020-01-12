// Rettangolo.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
