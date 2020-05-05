//  Task#12: 앞선 Display 6.1 예제의 struct CDAccountV1 구조체 두 개를 매개변수로 받아, 
//두 구조체의 멤버 변수의 값을 서로 바꾸는 swapStruct 함수를 작성하세요

#include <iostream>
using namespace std;

struct CDAccountV1 {
    double balance;
    double interestRate;
    int term;
};

void swapStruct(CDAccountV1 &v1, CDAccountV1 &v2) {
    CDAccountV1 temp = v1;
    v1 = v2;
    v2 = temp;
}

int main() {
    struct CDAccountV1 v1 = {10.0, 0.01, 60};

    struct CDAccountV1 v2 = {50.0, 0.02, 30};

    swapStruct (v1, v2);

    cout << "balance: " << v1.balance

            << " interest: " << v1.interestRate

            << " terms: " << v1.term << endl;
 

     cout << "balance: " << v2.balance

             << " interest: " << v2.interestRate

             << " terms: " << v2.term << endl;

    return 0;
}