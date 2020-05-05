#include <iostream>
using namespace std;

/*
 •    Task#16: 2차원 벡터에 대한 정보를 저장하는 Vector2D 클래스 구현

 */

class Vector2D {
//  Private 멤버로 정수형의 x, y 좌표를 가짐.
	int x,y;
public:
//  Parameter가 없는 생성자 구현: (0, 0) 벡터 생성
	Vector2D():x(0), y(0) {}
//  (int x, int y) 를 parameter로 가지는 생성자 구현
	Vector2D(int x, int y): x(x), y(y){}

//   출력을 위한 멤버 함수 구현
//   덧셈 (+), 뺄셈 (-), 비교 (==) 연산자 오버로딩
	Vector2D operator+(Vector2D& v2){
		return Vector2D(x+v2.x , y + v2.y);
	}
	Vector2D operator-(Vector2D& v2){
		return Vector2D(x - v2.x , y - v2.y);
	}

	bool operator==(Vector2D& v2){
		if( x == v2.x && y == v2.y) return true;
		return false;
	}
	void output() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

int main() {

	Vector2D v0, v1(2,2), v2(3,3), v3;
 
	v3 = v1 + v2;
	v3.output();

 	v3 = v2 - v2;
	v3.output();

	if (v3 == v0)
		cout << "Operator - works!";

	return 0;
}

/*
출력 예:
   (5,5)
   (0,0)
   “Operator – works!”
 */
