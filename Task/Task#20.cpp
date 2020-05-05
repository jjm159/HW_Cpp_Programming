#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	int cap;

	cout << "Enter capacity of this super array: ";
	cin >> cap;

	PFArrayI temp(cap);

	cout << "Enter up to " << cap << " nonnegative numbers.\n";
	cout << "Place a negative number at the end.\n";

	int next;

	cin >> next;

	while ((next >= 0) && (!temp.full( )))
	{
      temp.addElement(next);
      cin >> next;
	}

	cout << "You entered the following " << temp.getNumberUsed( ) << " numbers:\n";

	int index;
	int count = temp.getNumberUsed( );

	for (index = 0; index < count; index++)
		cout << temp[index] << " ";

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

–       아래 main 함수가 올바르게 작동하도록함
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
