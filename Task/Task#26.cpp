#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Quad {
	T a,b,c,d;
public:
	Quad(const T& _a, const T& _b, const T& _c, const T& _d): a(_a), b(_b), c(_c), d(_d) {}
	friend ostream& operator<< ( ostream& out, const Quad& quad) {
		out << '<'<< quad.a << ", " << quad.b << ", " << quad.c << ", " << quad.d << '>'; 
		return out;
	}
};

int main () {
  Quad<int> qi(5,6,7,8);
  Quad<string> qs("hello", "C++", "programming", "language");
  Quad<double> qd(1.1, 2.2, 3.3, 4.4);

  cout << qi << endl;
  cout << qs << endl;
  cout << qd << endl;

  return 0;
}

/*
 •        Task#26. 다양한 type의 element를 4개씩 저장 및 출력할 수 있는 Quad template class 를 정의하여, 아래 main function 이 올바르게 작동하게 하세요.
–       4개의 매개변수를 가지는 생성자 정의
–       << 연산자 오버로딩

•        출력 예

–       Elements are : <5, 6, 7, 8>
–       Elements are : <“hello”, “C++”, “programming”, “language”>
–       Elements are : <1.1, 2.2, 3.3, 4.4>
 
 */
