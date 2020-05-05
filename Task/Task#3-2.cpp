#include <iostream>
using namespace std;
int main()
{
    float fah = 0.0f;
    float cel = 0.0f;
    
    cout << "Put the degree in Celsius: ";
    cin >> cel;

    fah = cel * 1.8f + 32.0f;

    cout << "The degree in Fahrenheit is " << fah << endl;

    return 0;
}


/*
Task#3-2

섭씨 온도를 입력받아 화씨 온도로 환산하여 출력하는 프로그램을 작성하세요. 

변환공식: 화씨온도 = 1.8*섭씨온도 + 32.0

출력 예 (빨간 글씨는 입력값)

Put the degree in Celsius: 21

The degree in Fahrenheit is 69.8
*/