#include <iostream>
using namespace std;

int main() {

    int a[4][4] = {10, 20, 30, 40, 5, 4 ,3, 99, 55, 100, 42, 100, 0, 105, 2, 11};

    int firstMax = 0, secondMax = 0;

    for(int i = 0; i<4; i++) {
        for(int j=0; j < 4; j++) {
            if(firstMax < a[i][j]){
                secondMax = firstMax;
                firstMax = a[i][j];
            }
        }
    }

    cout << "The largest number is " << firstMax << endl;;

    cout << "The second-largest number is " << secondMax << endl;;
   
    return 0;
}

/*
The largest number is 105

The second-largest number is 100
*/