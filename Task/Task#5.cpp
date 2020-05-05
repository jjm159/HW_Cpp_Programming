#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main() {

    string fileName = "C++Programming.txt";
    string inputString;

    fstream inputStream;
    inputStream.open(fileName);
    if(!inputStream){
        cout << "error" << endl;
    };

    while( !inputStream.eof() ){
        inputStream >> inputString;
        if( inputString == "hate")
            inputString = "love";
        cout << inputString << ' ';
    }

    inputStream.close();

    return 0;
}

// 파일포인터는, 현재 가리키는 데이터를 읽은 후 이동된다. 
// 마지막 데이터를 읽은 후 파일포인터는 eof를 가리킨다.
// (eof는 물리적인 데이터 형태로 파일에 저장돼 있는 게 아니다.(명품 씨쁠쁠 625p참고))
// 이 때 eof함수를 호출하면 true.
// 이 때 파일 읽기를 시도하면 반환값으로 eof 반환.