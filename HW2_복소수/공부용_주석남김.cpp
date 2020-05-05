/*
 a + bi 형태의 cout 출력 지원
 복소수 간 사칙연산 및 복소수와 실수 사이의 사칙연산 지원
 Encapsulation 원칙에 따라, 내부 데이터는 private화

 ---

 Requirements 및 배점
 0.5 : NComplex 클래스 정의: 두 개의 인자(실수부, 허수부)를 가지는 생성자와 0개의 인자를 가지는 디폴트 생성자(0+0i로 초기화)를 구현.
  - 멤버변수 Private으로
 3.0점 : 사칙연산 지원 -> 복소수-복소수  복소수-실수  실수-복소수
 0.5점 : cout 출력 지원 - "a + bi" 형태
 0.5점 : Divide by 0 - 오류처리. 오류메세지 + exit(0)
 0.5점 : 보고서 - 1. 문제정의 : 내가 만들어야하는 기능정의(클래스, 생성자, 연산자 오버리딩 등등) 2. 프로그램 설계 : 위에서 정의한 문제 해결 위해 구체적 방법 제시.
 
 */

// 복소수 i끼리 곱하면 -1이 된다! 
// 복소수 * 복소수 -> 이떄만 imagin*imagin을 -1 * 처리해주면 된다. 

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class NComplex {

	const double realNum, imaginNum;

public:
	NComplex():realNum(0), imaginNum(0) {}
	NComplex(double real, double imag): realNum(real), imaginNum(imag) {}

	// friend를 쓰면 이게 필요가 없다. 
	//const double getRealNum() { return realNum; }
	//const double getimaginNum() { return iamginNum; }


	// + - / *
	// 실수값을 첫번째인자로 받고, 두번쨰 인자로 NComplex객체를 받으려면, 전역 연산자를 오버로딩해야한다. 그래서 friend가 필요하다. - 보고서에 언급. - 먼저 friend 없이도 되는지 test해보고. 

	// 반환값의 타입을string으로 바로하지 않고 NComplex를 한 이유 : 그게 더 의미상으로 맞으니까. 
	// new로 새로운 메모리를 할당해서 메모리 주소를 반환하는 방법을 사용하지 않고 임시객체를 반환한 이유 : 메모리 관리 귀찮아짐.

	// 인자를 하나만 받는 연산자 오버로딩 -> 안보이게 첫번째 인자로 객체를 받는다.모든 멤버함수는 첫번째 인자로 객체를 받는다. 그래서 이건 클래스의 멤버함수다. 멤버함수를 구현할 때, this를 쓰지 않고 멤버함수에 접근해도, this로 받은 객체의 멤버변수라고 인식한다. 그래서 this를 안써줘도 된다. 
   	// 인자를 두 개 이상 받는 연산자 함수는 전역함수다. 전역함수는 클래스 외부로 취급. 그래서 friend가 필요하다.	
// return된 NComplex 객체는 <<를 만나서 overloding된 << operator가 실행.  
	NComplex operator+(double operand) {
		return NComplex( operand + realNum , imaginNum);
		// 복사 방식으로 익명 객체 리턴. // new로 할당하면 메모리 해제 귀찮.
	} // 객체.operator+(operand) 와 같다. 즉, operator+는 NCoplex의 멤버함수인것.

// 얘는 왜 friend를 쓰지 않을까? -> 복사생성자를 생각해보자. 
	// 같은 클래스 객체의 함수에서는, private에 직접 접근 가능한듯! -> 실험해보자. 
	NComplex operator+(NComplex& operand) {
		return NComplex( realNum + operand.realNum , imaginNum + operand.imaginNum);
	} // 객체 + operand객체 -> 객체.operator+(operand객체)와 같다. 즉, operator+는 NCoplex의 멤버함수인것.

// 얘는 friend 필요. friend안쓰면, get함수 필요할 것. 또는 멤버변수를 public으로 하거나. 
	friend NComplex operator+(double operand1, NComplex& operand2) {
		return NComplex( operand2.realNum + operand1, operand2.imaginNum);
	} // operator+(객체1, 객체2) 와 같다. 즉, operator+는 전역함수인 것. 


// 이렇게 생각해보자. 
	//단항연산자는 operand가 하나, 그래서 인자로 하나만 받을 수 있어. 다만 전위,후위를 구분하기 위한 두번째인자를 받을 뿐.
	//이항연산자(<<, +, -, *, / 등등)는 operand가 두개, 그래서 인자로 두개만 받을 수 있어. 멤버함수 연산자 함수의 경우 앞에 인자는 이 연산자를 호출한 객체의 포인터임. 전역 연산자 함수일때만 두개를  다 받음.

	// - 연산은 앞 뒤 순서 중요.
	NComplex operator-(double operand) {
		return NComplex(realNum - operand, imaginNum);
	}
	NComplex operator-(NComplex& operand) {
		return NComplex(realNum - operand.realNum, imaginNum - operand.imaginNum);
	}
	friend NComplex operator-(double operand1, NComplex operand2) {
		return NComplex( operand1 - operand2.realNum,  - operand2.imaginNum);
	}
	

	NComplex operator*(double operand) {
		return NComplex(operand * realNum, operand * imaginNum);
	}
	//NComplex operator*(NComplex& operand) {
	//	return NComplex(realNum * operand.realNum - imaginNum * operand.imaginNum, realNum*operand.imaginNum + imaginNum*operand.realNum);
	//}
	friend NComplex operator*(NComplex operand1, NComplex operand2) {
		return NComplex(operand1.realNum * operand2.realNum - operand1.imaginNum * operand2.imaginNum, operand1.realNum*operand2.imaginNum + operand1.imaginNum*operand2.realNum);
	}
	friend NComplex operator*(double operand1, NComplex operand2) {
		return NComplex(operand1 * operand2.realNum, operand1 * operand2.imaginNum);
	}


	// 분모의 실수화, 분모가 0일때 -> 이게 관건!!!
	// a + bi / x + yi = (a+bi)(x-yi)/(x^2-y^2)
	NComplex operator/(double operand) {
		zeroCheck(operand);
		return NComplex(realNum / operand, imaginNum / operand);
	}
	NComplex operator/(NComplex& operand) {
		zeroCheck(operand);
							//expects an l-value for 1st argument : *this로는 연산자오버로딩의 this로 못받음. this는 l-value여야함.
		NComplex dividend = *this * NComplex(operand.realNum,-operand.imaginNum); // 곱하기 오버로딩을 여기서 써먹는다.
		// 여기서 문제: *연산자 호출할 수 있는, 맞는 매개변수 타입이 없다고 나옴. 
		// friend를 쓰지 않은 NComplex타입으로 하나 인자로 받는 함수에서는, expects an l-value for 1st argument 에러가 났고,
		// friend를 쓰는 NComplex 타입의 인자를 두 개 받는 함수에서는 expects an l-value for 2nd argument 에러가 났다. 
		// 이것은 매개변수를 참조로 선언하여 발생한 문제. 참조를 지우고 복사방식으로 받았더니 됐다!.
		// 기억하자! 참조변수는 l-value만 받을 수 있다. ex) int& a = b;

		double divisor = pow(operand.realNum,2) + pow(operand.imaginNum,2); 
		return NComplex(dividend.realNum/divisor, dividend.imaginNum/divisor);
	}
	friend NComplex operator/(double operand1, NComplex operand2) {
		operand2.zeroCheck(operand2);
		NComplex dividend = operand1 * NComplex(operand2.realNum, -operand2.imaginNum);
		double divisor = pow(operand2.realNum,2) + pow(operand2.imaginNum,2); 
		return NComplex(dividend.realNum/divisor, dividend.imaginNum/divisor);
	}
	void zeroCheck(NComplex divisor){
		if(divisor.realNum || divisor.imaginNum) return; // 둘 중에 하나만 0이 아니어도 괜찮.
		cout << "Error: divide by zero" << endl;
		exit(1);
	}
	void zeroCheck(double divisor){
		if(divisor) return;
		cout << "Error: divide by zero" << endl;
		exit(1);
	}
	
	
	string renderOutForm() {
		return removeLastZero(to_string(realNum)) + " + " + removeLastZero(to_string(imaginNum)) + "i";
	}
	string removeLastZero(string str){
		// 끝에서부터 0을 지워나감.
		// 0이 아닌 값을 만날때까지.
		// 처음 0이 아닌 값을 만났을 때, 그 값이 .이냐 .이 아닌 숫자냐 에 따라 달라짐.
		char zero = str.back();
		str.pop_back();
		while (zero == '0'){
			zero = str.back();
			if( zero != '0') break;
			str.pop_back();
		}
		if(zero == '.') {
			str.push_back('0');	
		}
	   		
		return str;
	}


	// 얘는 friend가 필요 없다. 직접 접근을 안할테니까. NComplex의 private에 직접접근할 일이 있다면, friend로 NCopmlex클래스 안에 선언해주는 게 맞다. 
	//friend ostream& operator<< (ostream& os, NComplex resultComplex){ 
	//	cout << resultComplex.renderOutForm();
	//	return os;
	//}//매개변수 resultComplex를 참조로 못받는 이유: 인자가 익명객체라서!

	// friend를 붙여야 전역연산자 오버로딩이 되나? // -> 응! 
};

// NComplex의 private에 대한 직접 접근이 없으면 friend필요 없음. 
// 여기서 renderOutForm함수가 public이라 아마 friend없어도 될것.
ostream& operator<< (ostream& os, NComplex resultComplex){ // resultComplex를 복사방식으로 받는 이유는 익명객체가 인자이기때문. 인자가 임시객체!
	cout << resultComplex.renderOutForm();
	return os;
} // operator<<( cout , NComplex객체 ); -> 이렇게 호출되는 거라고 생각해~!

int main(int argc, char* argv[]){

	NComplex n1(5.1, 2.2), n2(2.0, 2.0) ,n3;
	double d1 = 3.0;

// test.
	cout << "test +" << endl;
	cout << n1 + n2 << endl;
	cout << n1 + d1 << endl;
	cout << d1 + n1 << endl;

	cout << "test -" << endl;
	cout << n1 - n2 << endl;
	cout << n1 - d1 << endl;
	cout << d1 - n1 << endl;

	cout << "test *" << endl;
	cout << n1 * n2 << endl;
	cout << n1 * d1 << endl;
	cout << d1 * n1 << endl;

	cout << "test /" << endl;
	cout << n1 / n2 << endl;
	cout << n1 / d1 << endl;
	cout << d1 / n1 << endl;

	cout << "-- submit -- " << endl;
	cout << "n1+n2: " << n1 + n2 << endl;
	cout << "n1*n2: " << n1 * n2 << endl;
	cout << "n1-d1: " << n1 - d1 << endl;
	cout << "d1*n2: " << d1 * n2 << endl;
   	cout << "n1/n3: " << n1 / n3 << endl;	 

	// n3 에는 0 + 0i 가 들어있음. 
	// 복소수 객체가 제수일때, realNum이나 imaginNum이 0이면, 에러 

// divisor 제수(분모) / dividend 피제수(분자). 

	return 0;
}


/*
	7.1 + 4.2i
	5.8 + 14.6i
	2.1 + 2.2i
	6.0 + 6.0i
	Error: divide by zero

 */
