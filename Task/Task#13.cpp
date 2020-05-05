// •        Task#13: Display 6.3 예제의 DayofYear class를 직접 구현하고, 
//날짜를 조절해주는 adjustDay 멤버함수를 구현하세요. 
//해당 함수는 정수를 매개변수로 받아, 해당 숫자만큼 날짜를 더하거나 빼서 month, day 값을 조절합니다. 
// 이 때, 한 달이 30, 31 또는 28일임을 유의하세요 (윤년은 없다고 가정)
// •        출력 예:
// –       Adjusted date is September 9

#include <iostream>
using namespace std;

class DayOfYear {
public:
    void output();
    void adjustDay(int days);
    int month;
    int day;
};

void DayOfYear::output() {
    switch(month){
        case 1:
            cout << "January "; break;
        case 2:
            cout << "Febrary " ; break;
        case 3:
            cout << "March " ; break;
        case 4:
            cout << "April "; break;
        case 5:
            cout << "May " ; break;
        case 6:
            cout << "June " ; break;
        case 7:
            cout << "July "; break;
        case 8:
            cout << "August " ; break;
        case 9:
            cout << "September " ; break;
        case 10:
            cout << "October " ; break;
        case 11:
            cout << "November " ; break;
        case 12:
            cout << "December " ; break;
        default:
            cout << "Error in DayOfYear::output. Contact software vender";
    }
    cout << day;
}
void DayOfYear::adjustDay(int days){
    day += days;
    while(1){
        switch(month) {
        case 2:
            if(day > 28){
                day -= 28;
                month++;
            }
            if( month < 12 && day <= 28) return;
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day > 31){
                day -= 31;
                month++;
            }
            if( month < 12 && day <= 31) return;
            break;
        case 4: case 6: case 9: case 11:
            if(day > 30){
                day -= 30;
                month++;
            }
            if( month < 12 && day <= 30) return;
            break;
        }
        if(month > 12) month -= 12;
    }
}

int main (){
    DayOfYear d1;
    d1.month = 8;
    d1.day = 20;

    d1.adjustDay(20);    /* add 20 days to d1 */
    cout << "Adjusted date is ";
    d1.output();

    return 0;
}

