#include <iostream>
using namespace std;

int main() {
	char name[20];
	char feeling[50];
	char like[50];
	int year;
	int term;

	cout << "Hello! What is your name?" << endl;
	cin >> name;
	cout << "Hi " << name << ". Nice to meet you. How are you?" << endl;
	cin >> feeling;
	cout << "Do you like to study informatics in NBU?" << endl;
	cin >> like;
	cout << "Which year are you?" << endl;
	cin >> year;
	cout << "Which term you are in?" << endl;
	cin >> term;

	cout << "My name is " << name << endl << "I am feeling " << feeling << endl
		<< "I " << like << " like to study informatics in NBU" << endl
		<< "I am " << year << " year" << endl << "I am " << term << " term" << endl
		<< "Bye :)" << endl;
}