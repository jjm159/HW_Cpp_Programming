#include <iostream>
using namespace std;

class HotDogStand{
public:
    HotDogStand(string);
    string getName();
    int getNumSold();
    void justSold(int);
    static int getTotalNumSold();
private:
    string branchShopName;
    int soldHotDogs = 0;
    static int totalSoldHotDogs;
};
int HotDogStand::totalSoldHotDogs = 0;

HotDogStand::HotDogStand(string brandNameValue): branchShopName(brandNameValue){}
string HotDogStand::getName(){
    return branchShopName;
}
int HotDogStand::getNumSold(){
    return soldHotDogs;
}
void HotDogStand::justSold(int soldHotDogsNumbers){
    totalSoldHotDogs += soldHotDogsNumbers;
    soldHotDogs = soldHotDogsNumbers;
}
int HotDogStand::getTotalNumSold(){
    return totalSoldHotDogs;
}

int main()
{
    HotDogStand h1("SSU-1"), h2("SSU-2"), h3("CAU-1");

    h1.justSold(20);
    h2.justSold(50);
    h3.justSold(1);

    cout << h1.getName() << " has sold " << h1.getNumSold() << " hotdogs." << endl;
    cout << h2.getName() << " has sold " << h2.getNumSold() << " hotdogs." << endl;
    cout << h3.getName() << " has sold " << h3.getNumSold() << " hotdogs." << endl;
    cout << "Total sales are: " << HotDogStand::getTotalNumSold() << endl;

}
// •        출력 예:

// •        SSU-1 has sold 20 hotdogs.

// •        SSU-2 has sold 50 hotdogs.

// •        CAU-1 has sold 1 hotdogs.

// •        Total sales are: 71
