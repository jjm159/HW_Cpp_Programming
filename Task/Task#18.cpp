#include <iostream>
using namespace std;

class Vector2D {
	int x,y;
public:
	Vector2D():x(0), y(0) {}
	Vector2D(int x, int y): x(x), y(y){}
	friend Vector2D operator+(Vector2D& v1, Vector2D& v2){
		return Vector2D(v1.x+v2.x , v1.y + v2.y);
	}
	friend Vector2D operator-(Vector2D& v1,Vector2D& v2){
		return Vector2D(v1.x - v2.x , v1.y - v2.y);
	}
	friend bool operator==(Vector2D& v1, Vector2D& v2){
		if( v1.x == v2.x && v1.y == v2.y) return true;
		return false;
	}
	friend Vector2D operator*(int scala, Vector2D& vec){
		return Vector2D(scala*vec.x, scala*vec.y);
	}
	friend int operator*(Vector2D& v1, Vector2D& v2){
		return v1.x*v2.x + v1.y*v2.y;
	}

	void output() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	friend ostream& operator<<(ostream& os, Vector2D v){
	cout << "(" << v.x << "," << v.y << ")";
	return os;
}
};


int main(int argc, char* argv[]){

	Vector2D v0, v1(2,2), v2(3,3), v3;

	cout << v1 << endl;   // (2,2)
	cout << v1 + v2 << endl; // (5,5)

	return 0;
}

/*

 •        Task#18: 2차원 벡터에 대한 정보를 저장하는 Vector2D 클래스 확장

       << 연산자 오버로딩으로 cout 지원가능 하도록 구현

•        출력 예:

       (2,2)
       (5,5)

 */
