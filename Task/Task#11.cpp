#include <iostream>
using namespace std;

int add(int i1, int i2) {
    return i1 + i2 ;
}
double add(double i1, double i2) {
    return i1 + i2 ;
}
string add(string i1, string i2) {
    return i1 + i2 ;
}

int main(void)
{
   int i1 = 10, i2 = 30;

   double d1 = 0.5, d2 = 3.5;

   string s1 = "Hello", s2 = "World";

   cout << add(i1, i2) << ", ";
   // double 타입이어도 소수점 이하의 0은 생략되길래,
   // 다음 코드를 추가하여 출력하게 만들었습니다.
    cout << fixed;
    cout.precision(1);
    cout << add(d1, d2) << ", "
        << add(s1, s2) << endl;

    return 0;
}