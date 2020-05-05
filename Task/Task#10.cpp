#include <iostream>
using namespace std;

void fillArray(int *arr, int num) {
    cout << "Put array elements: ";
    for(int i = 0; i< num ; i++){
        cin >> arr[i];
    }
}
void printArray(int *arr, int num) {
    cout << "Array elements are ";
    for(int i = 0; i< num ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

   int arr[5];

   fillArray(arr, 5);

   printArray(arr, 5);

   return 0;
}

//   Put array elements: 10 20 30 40 50

//      Array elements are 10 20 30 40 50

