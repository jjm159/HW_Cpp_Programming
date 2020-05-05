#include <iostream>
using namespace std;

int main()
{
    int hourValue = 0;      
    cout << "Put the hour value: ";
    cin >> hourValue;

    int minuteValue = 0;
    cout << "Put the minute Value: ";
    cin >> minuteValue;

    cout << "The time is " << hourValue << ":"<< minuteValue << endl;

    return 0;

}

/*
Task#3-1

시간 값과 분 값의 입력을 사용자에게 요청하고, 아래 예제와 같은 형식으로 출력하는 프로그램을 작성하세요.

출력 예 (빨간 글씨는 입력값)

Put the hour value: 9

Put the minute value: 30

The time is 9:30
*/