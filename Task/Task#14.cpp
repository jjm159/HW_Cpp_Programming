// •  Task#14: Display 7.1의 DayOfYear 클래스의 생성자를 overloading 하여,
//   아래 2종류의 새로운 생성자를 추가하여 확장하세요.
// –  (Month축약형) 를 매개변수로 받아, 해당월의 1일로 설정
// –  (Month축약형, Day) 를 매개변수로 받아, 해당월 및 날짜를 설정
// •   Month 축약형: Jan, Feb, Mar, Apr, …., Dec.
// •    입출력 예:
// –    Put an abbreviation of a month (3 chars) and a day (number): Mar 29
// –  March 29


#include <iostream>
#include <cstdlib>

using namespace std;


class DayOfYear 
{
public:
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(int monthValue);
    DayOfYear(string);
    DayOfYear(string, int);
    DayOfYear();
    void output();
private:
    int month;
    int day;
    void testDate();
    string monthList[12] = {
        "Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    string monthListFullName[12] = {
        "January","Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
};
DayOfYear::DayOfYear(int monthValue, int dayValue): month(monthValue), day(dayValue){
    testDate();
}
DayOfYear::DayOfYear(int monthValue):month(monthValue), day(1) {
    testDate();
}
DayOfYear::DayOfYear() : month(1), day(1) { }

void DayOfYear::testDate() {
    if( (month < 1) || (month > 12) ) {
        cout << "Illegal month value!\n";
        exit(1);
    }
    if( (day < 1) || (day > 31)){
        cout << "Illegal day value!" << endl;
        exit(1);
    }
}

void DayOfYear::output(){
    cout << monthListFullName[month - 1] << " " << day << endl;
}

DayOfYear::DayOfYear(string sMonthValue): month(0), day(1){
    for(int i = 0; i < 12; i++){
        if(monthList[i] == sMonthValue){
            month = i + 1;
            return;
        }
    }
    testDate();
}
DayOfYear::DayOfYear(string sMonthValue, int dayValue): month(0), day(dayValue) {
    for(int i = 0; i < 12; i++){
        if(monthList[i] == sMonthValue){
            month = i + 1;
            return;
        }
    }
    testDate();
}



int main()
{
      string sMonth;

      int day;

      cout << "Put an abbreviation of a month (3 chars) and a day (number): ";

      cin >> sMonth >> day;

      DayOfYear date1(sMonth), date2(sMonth, day);

      date1.output();

      date2.output();
}

