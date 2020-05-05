#include <iostream>
using namespace std;

// 이 방법 말고 세개의 값 내림차순 정리하는 방법 뭐가 있을 지 고민해보자. 
void sort_three (int& a, int& b, int& c)
{
   int sortArray[] = {a,b,c};
   for(int i = 0 ; i < 2; i++ ){
      for(int j = 0; j < 3 - i; j++ ) {
         if (sortArray[j] < sortArray[j+1])
         {
            int temp = sortArray[j];
            sortArray[j] = sortArray[j+1];
            sortArray[j+1] = temp;
         }
      }
   }
   a = sortArray[0];
   b = sortArray[1];
   c = sortArray[2];
}

int main ()
{
   int i1 = 100, i2 = 90, i3 = 500;

   sort_three (i1, i2, i3);

   cout << "Three numbers are: "

        << i1 << " , " << i2 << " , " << i3 << endl;

}

/*
Task#9:  아래 sort_three라는 함수를 완성하세요. 
해당 함수는,  첫 번째 parameter가 가장 큰 값을, 
두번째는 두번째로 큰 값, 세번째는 가장 작은 값을 
갖도록 각 변수의 값을 변경하도록 하세요.
*/

// Three numbers are: 500 , 100 , 90
 