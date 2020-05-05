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

	NComplex operator+(double operand) {
		return NComplex( operand + realNum , imaginNum);
	} 

	NComplex operator+(NComplex& operand) {
		return NComplex( realNum + operand.realNum , imaginNum + operand.imaginNum);
	}

	friend NComplex operator+(double operand1, NComplex& operand2) {
		return NComplex( operand2.realNum + operand1, operand2.imaginNum);
	} 

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
	friend NComplex operator*(NComplex operand1, NComplex operand2) {
		return NComplex(operand1.realNum * operand2.realNum - operand1.imaginNum * operand2.imaginNum, operand1.realNum*operand2.imaginNum + operand1.imaginNum*operand2.realNum);
	}
	friend NComplex operator*(double operand1, NComplex operand2) {
		return NComplex(operand1 * operand2.realNum, operand1 * operand2.imaginNum);
	}


// a + bi / x + yi = (a+bi)(x-yi)/(x^2-y^2)
	NComplex operator/(double operand) {
		zeroCheck(operand);
		return NComplex(realNum / operand, imaginNum / operand);
	}
	NComplex operator/(NComplex& operand) {
		zeroCheck(operand);
		NComplex dividend = *this * NComplex(operand.realNum,-operand.imaginNum); 

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
		if(divisor.realNum || divisor.imaginNum) return; 
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
};

ostream& operator<< (ostream& os, NComplex resultComplex){ 
	cout << resultComplex.renderOutForm() << endl;
	return os;
}

int main(int argc, char* argv[]){

	NComplex n1(5.1, 2.2), n2(2.0, 2.0) ,n3;
	double d1 = 3.0;


	cout << "n1+n2: " << n1 + n2 << endl;
	cout << "n1*n2: " << n1 * n2 << endl;
	cout << "n1-d1: " << n1 - d1 << endl;
	cout << "d1*n2: " << d1 * n2 << endl;
   	cout << "n1/n3: " << n1 / n3 << endl;	 


	return 0;
}










