#include <iostream>
using namespace std;

float meterToMile(float distance) {
    const float conversionRatio = 1609.34;
    float result = distance / conversionRatio;
    return result;
}

int main(){
    float distance = 184.6;

    cout << "The distance is " 
        << meterToMile(distance) << " miles"<< endl;

    return 0;
}

//숭실대입구에서 형남공학관까지의 거리는 약 184.6 미터이다. 
//이 정보를 변수에 저장한 후, 
//이를 마일 단위로 환산하여 출력하는 프로그램을 작성하세요.
// 1 마일은 1.60934 KM // 1km = 1000m // 1mile == 1609.34m
// 1mile : x = 1609.34 m(const) : 184.6(meter)
// const * x = 1mile * meter
// x = meter / const
// The distance is 0.114705 miles