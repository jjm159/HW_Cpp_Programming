#include <iostream>

#include <vector>



using namespace std;



class Point {

public:

    int x,y;

    Point(int x, int y):x(x),y(y) {

    }

};



class Figure{

public:

    virtual void draw() {}

};



class Rectangle: public Figure {

    Point a,b;

public:

    Rectangle(const Point& p1, const Point& p2): a(p1), b(p2) {

    }

    void draw() {

        cout << "A rectangle from (" << a.x << ", " << a.y << ") to (" <<b.x << ", " << b.y << ")" << endl;

    }



};





class Circle: public Figure {

    Point center;

    double radius;

public:

    Circle(const Point& p, double r): center(p), radius(r){

    }

    void draw() {

        cout << "A circle with the center of (" << center.x << ", " << center.y << ") and the radius of " << radius << endl;

    }

};



void draw2figues (Figure& f1, Figure& f2)

{

    cout << "First figure is: ";

    f1.draw();

    cout << "Second figure is: ";

    f2.draw();

}



int main ()

{

    Point p1(0,0), p2(2,2);

    Rectangle r1 (p1, p2);

    Circle c1 (p1, 2);

    draw2figues(r1, c1);

}
