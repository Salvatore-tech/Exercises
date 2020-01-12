// Square.cpp : Write a class Point and test the inerithance with the class Point3d
//

#include <iostream>
using namespace std;
class Point {
    float x, y;
public:
    Point();
    Point(float x, float y) { this->x = x; this->y = y; };
    void setX(float x, float y) { this->x = x;  };
    void setY(float y) { this->y = y; };
    void getX() { cout << "X: " << x << endl; };
    void getY() { cout << "Y: " << y << endl; };
};

class Point3d:public Point {
    float z;
public:
    Point3d(float x, float y, float z) :Point(x, y) { this->z = z; } //Il costruttore della classe derivata chiama il costruttore della classe base
    void getZ() { cout << "Z: " << z << endl; }
};



int main()
{
    Point P1(3.3, 4.4);
    Point3d P2(4.4, 5.8, 10.2);
    P1.getX(); P1.getY(); // Getting coords from P1
    P2.getX();  P2.getY(); P2.getZ(); // Getting coords from P2
    
}
