#include <iostream>
#include <string>

using namespace std;

int main() {

    int deiscreteMathScore = 0;
    cout << "Put the discrete math score: " ;
    cin >> deiscreteMathScore;

    int programmingLanguageScore = 0;
    cout << "Put the programming language socore: " ;
    cin >> programmingLanguageScore;

    int dataStructureScore = 0;
    cout << "Put the date structure score: " ;
    cin >> dataStructureScore;

    int sumOfScore = deiscreteMathScore + programmingLanguageScore + dataStructureScore;
    float averageOfScore = (float)sumOfScore / 3;

    string grade;
    if ( averageOfScore > 95 && averageOfScore <= 100) grade = "A+";
    else if ( averageOfScore > 90 ) grade = "A0";
    else if ( averageOfScore > 85 ) grade = "B+";
    else if ( averageOfScore > 80 ) grade = "B0";
    else if ( averageOfScore > 75 ) grade = "C+";
    else if ( averageOfScore > 70 ) grade = "C0";
    else if ( averageOfScore <= 70 && averageOfScore >= 0) grade = "F";

    cout.precision(4);
    cout << "The average score is " << averageOfScore
        << " and the grade is " << grade;
   
    return 0;
}