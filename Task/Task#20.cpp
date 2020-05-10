#include <iostream>
#include <cstdlib>
using namespace std;

class PFArrayI {
	int *a; 
	int capacity; // total memory size.
	int used; //  a number of used memory in array.
public:
	PFArrayI():capacity(50), used(0) { a = new int[50]; }
	explicit PFArrayI(int size):capacity(size), used(0) {
		a = new int[capacity];
	}
	PFArrayI(const PFArrayI &I): capacity(I.capacity), used(I.capacity) {
		a = new int[capacity];
		for(int i = 0; i< I.used; i++) a[i] = I.a[i];
	}
	void addElement (int ele) {
		if(used >= capacity) {
			cout << "Attempt to exceed capacity in PFArrayI." << endl;
			exit(0);
		}
		a[used++] = ele;
	}
	bool full() const { return (used == capacity); }
	int getCapacity() { return capacity; }
	int getNumberUsed() { return used; }
	void emptyArray() { used = 0; }
	int& operator[] (int index) { return *(a + index); }
	PFArrayI& operator= (const PFArrayI& obj) {
		if( obj.capacity != capacity ) {
			delete[] a;
			a = new int[obj.capacity];
		}
		capacity = obj.capacity;
		used = obj.used;
		for(int i = 0; i < obj.used;i++) a[i] = obj.a[i];
		return *this; // 
	}
	~PFArrayI() { delete[] a; }
};

int main(int argc, char* argv[]){
	int cap;

	cout << "Enter capacity of this super array: ";
	cin >> cap;

	PFArrayI temp(cap);

	cout << "Enter up to " << cap << " nonnegative numbers.\n";
	cout << "Place a negative number at the end.\n";

	int next;

	cin >> next;

	while ( ( next >= 0 ) && ( !temp.full() ) ) {
      temp.addElement(next);
      cin >> next;
	}

	cout << "You entered the following " << temp.getNumberUsed( ) << " numbers:\n";

	int index;
	int count = temp.getNumberUsed( );

	for (index = 0; index < count; index++) cout << temp[index] << " ";

	cout << endl;

	return 0;
}


/*
 •        Task#20. Display 10.10 & 10.11 을 참고해서 PFArrayI class를 구현하세요. 해당 클래스는 아래와 같은 특성을 지니도록하세요

–       내부적으로 double 대신 int 형의 데이터를 저장하도록 함. 이 때, Display 10.10 에 선언된 아래 멤버 함수를 적절하게 구현 (display 10.11 참고)

•        PFArrayI ()
•        PFArrayI (int)
•        PFArrayI (const PFArrayI&)
•        Void addElement (int)
•        Bool full() const
•        Int getCapacity()
•        Int getNumberUsed()
•        Void emptyArray()
•        int& operator[] (int)
•        PFArrayI& operator= (const PFArrayI&)
•        ~PFArrayI();
------------------------------------------
•        출력 예

Enter capacity of this super array: 10
Enter up to 10 nonnegative numbers.
Place a negative number at the end.

10
20
30
40
-1

You entered the following 4 numbers:
10 20 30 40
 
 */
