#include <iostream>
using namespace std;
/*
	Task#17: 2차원 벡터에 대한 정보를 저장하는 Vector2D 클래스 확장

	Task#16 에서 구현했던 덧셈, 뺄셈, 비교 연산자 오버로딩을 friend function 으로 변경.
	스칼라 * 벡터 연산자 오버로딩을 friend function 으로 구현
	벡터 * 벡터 연산자 오버로딩 (벡터의 내적 연산) 을 member function 으로 구현: return 값을 주의할것.
*/

class Vector2D {
	int x,y;
public:
	Vector2D():x(0), y(0) {}
	Vector2D(int x, int y): x(x), y(y){}
// friend로.
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
// 스칼라 벡터
	friend Vector2D operator*(int scala, Vector2D& vec){
		return Vector2D(scala*vec.x, scala*vec.y);
	}
// 벡터 벡터
	friend int operator*(Vector2D& v1, Vector2D& v2){
		return v1.x*v2.x + v1.y*v2.y;
	}

	void output() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};


int main(int argc, char* argv[]){

	Vector2D v0, v1(2,2), v2(3,3), v3;

	int k = 2;

	v3 = k*v1; 
	v3.output();  // (4,4)

	cout << v1 * v2 << endl; // 12

	return 0;
}


/*
•        출력 예:

       (4,4)
       12 
 */
