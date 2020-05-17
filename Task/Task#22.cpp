#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() {
		printConMessage("A");	
	}
	~A() {
		printDeMessage("A");
	}
	void printConMessage(string&& id) {
		cout << "Constructor in class " << id << " executed" << endl;
	}	
	void printDeMessage(string&& id) {
		cout << "Destructor in class " << id << " executed" << endl;
	}
};

class B: public A {
	int b;
public:
	B() {
		printConMessage("B");	
	}
	~B() {
		printDeMessage("B");
	}
};

class C: public B {
	int c;
public: 
	C() {
		printConMessage("C");
	}
	~C() {
		printDeMessage("C");
	}
};

int main() {
	C* pc = new C;
	delete pc;
}

/*
 •        Task#22: Class A, B, C 를 아래의 상속관계를 가지도록 정의하세요.

–       Class A

–       Class B : public A

–       Class C : public B

•        각 클래스는 int 형의 임시 public 멤버 변수 하나씩을 가지도록 하세요.

•        각 클래스의 constructor와 destructor에 해당 멤버 함수가 실행되었음을 알리는 cout stmt를 넣어, constructor와 destructor의 실행 순서를 확인하세요.
 */
