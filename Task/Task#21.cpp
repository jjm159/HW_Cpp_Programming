#include <iostream>
#include <cstdlib>
using namespace std;

class Employee {
protected:
	string name;
	string ssn;
	double netPay;
public:
	Employee(): name("No name yet"), ssn("No Number yet"), netPay(0) {}
	Employee(const string& theName, const string& theSsn): name(theName), ssn(theSsn), netPay(0) {}
	string getName() const { return name; }
	string getSsn() const { return ssn; }
	double getNetPay() const { return netPay; }
	void setName(const string& newName) { name = newName; }
	void setSsn(const string& newSsn) { ssn = newSsn; } 
	void setNetPay(double newNetPay) { netPay = newNetPay; }
	void printCheck() const {
		cout << endl;
		cout << "ERROR: printCheck FUNCTION CALLED FOR AN" << endl;
		cout << "UNDIFFERENTIATED EMPLOYER. Aborting the program." << endl;
		cout << "Check with the author of the program about this bug." << endl;
		exit(1);
	}
};

class HourlyEmployee: public Employee {
	double wageRate;
	double hours;
public:
	HourlyEmployee(): Employee(), wageRate(0), hours(0) {}
	HourlyEmployee(const string& theName, const string& theNumber, double theWageRate, double theHours): Employee(theName, theNumber), wageRate(theWageRate), hours(theHours) {}
	void setRate(double newWageRate){ wageRate = newWageRate; }
	double getRate() const { return wageRate; }
	void setHours(double hoursWorked) { hours = hoursWorked;}
	double getHours() const { return hours; }
	void printCheck() {
		setNetPay(hours * wageRate);
		cout << "__________________________________" << endl;
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars" << endl;
		cout << "__________________________________" << endl;
		cout << "Check Stub: Not NEGOTIABLE" << endl;
		cout << "EmployeeNumber: " << getSsn() << endl;
		cout << "Hourly Employee. " << endl << "Hours worked: " << hours 
			<< " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
		cout << "__________________________________" << endl;
	}
};

class UnivHourlyEmployee: public HourlyEmployee {
	string univName;
public:
	UnivHourlyEmployee(): HourlyEmployee(), univName("Not name yet") {}
	UnivHourlyEmployee(const string& theName, const string& theNumber, const string& theUnivName, double theWageRate, double theHours)
		: HourlyEmployee(theName, theNumber, theWageRate, theHours), univName(theUnivName) {} 
	void printInfo(){
		cout << "Employee Name: " << name << ", Affliation: " << univName << endl;
		printCheck();
	}
};

int main()
{
    UnivHourlyEmployee john("JohnDoe", "123456", "SSU", 10, 40);
    john.printInfo();
}
