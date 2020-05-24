#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
public:
	int x,y;
};

class Figure {
public:
	virtual void setValue() = 0;
	virtual void draw() = 0; 
	virtual ~Figure() {}
};

class Circle: public Figure { 
	Point center;
	double radius;
public:
	void draw() {
		cout << "A circle with the center of (" << center.x << ", " << center.y << ") and the radius of " << radius << endl;
	}
	void setValue() {
		cout << "Enter x,y coordinates of the center: ";
		cin >> center.x >> center.y;
		cout << "Enter the radius: ";
		cin >> radius;
	}
};

class Rectangle: public Figure {
	Point a,b;
public:
	void draw() {
		cout << "A rectangle from (" << a.x << ", " << a.y << ") to (" << b.x << ", " << b.y << ")" << endl;
	}
	void setValue() {
		cout << "Enter x,y coordinates of P1: ";
		cin >> a.x >> a.y;
		cout << "Enter x,y coordinates of P2: ";
		cin >> b.x >> b.y;
	}
};

int main() {
	vector<Figure *> f;

	string inputString;
	while( 1 ){
		cout << "Enter figure type or draw: ";
		cin >> inputString;
		if(inputString == "draw") break;
		if( inputString == "circle") 
			f.push_back(new Circle());
		else if( inputString == "rectangle")
			f.push_back(new Rectangle);
		f.back()->setValue();
	}

	for( int i = 0 ; i< f.size() ; i++){
		f[i]->draw();
		delete f[i];
	}

	return 0;

}
