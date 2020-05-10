#include <iostream>

using namespace std;

int* allocArray(int size) {	return new int[size]; }
void printArray(const int * arr) { cout << "Array elements are: " << *arr << ' ' << *(arr+1) << ' ' << *(arr+2) << endl; }
void freeArray(const int * arr) { delete [] arr; }

int main(int argc, char* argv[]){
	int* arr;
	int size;

	cout << "Enter the array size: ";
	cin >> size;

	arr = allocArray (size);

	for (int i=0; i<size; i++){
		cout << "Put an array element: ";
		cin >> arr[i];
	}

	printArray(arr);
	freeArray(arr);

	return 0;
}


/*
 
 •        Task#19: 동적할당배열 관련 아래 함수를 작성하여, 제시한 main 함수가 올바르게 작동하도록 하세요.

       allocArray(): 사용자가 원하는 크기만큼의 정수형 배열을 동적할당
       printArray(): 배열의 내용을 출력
       freeArray(): 동적할당된 배열의 메모리를 해제

•        입출력 예:

       Enter the array size: 3
       Put an array element: 10
       Put an array element: 20
       Put an array element: 30
       Array elements are: 10 20 30

 */
