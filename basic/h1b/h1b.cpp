#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter age: ";
	cin >> age;
	if (age > 0) {
		unsigned days = age * 365;
		unsigned hours = days * 24;
		unsigned minutes = hours * 60;

		cout << "days lived: " << days << endl;
		cout << "hours lived: " << hours << endl;
		cout << "minutes lived: " << minutes << endl;
	}
	else {
		cout << "invalid age" << endl;
	}
}