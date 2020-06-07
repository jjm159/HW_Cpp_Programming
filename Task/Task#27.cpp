#include <iostream>
#include <map>
using namespace std;
int main() {
	map<int, string> m;
	int id;
	string name;
	while(1){
		cout << "Enter the ID number: " ;
		cin >> id;
		if(!id) break;
		cout << "Enter the student name: ";
		cin >> name;
		m[id] = name;

	} 
	cout << "Enter the searching ID number: ";
	cin >> id;
	cout << "The student name is "<< m[id] << endl;
	return 0;
}
