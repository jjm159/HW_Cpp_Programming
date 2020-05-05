#include <string>
#include <iostream>
using namespace std;

int main() {
    
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n = 10;

    for (int i = 0; i < n-2 ; i++)
        cout << *(a+i) + *(a+i+1) + *(a+i+2) << endl;

    return 0;
}
