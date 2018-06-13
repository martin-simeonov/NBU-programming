#include "Company.h"
#include <iostream>
#include <cstring>
using namespace std;

Company::Company()
	: _name(""), _employeeCount(0)
{}

Company::Company(const char* name, int employeeCount)
	: _name(new char[strlen(name) + 1]), _employeeCount(employeeCount)
{
	strcpy_s(_name, strlen(name) + 1, name);
}

Company::Company(const Company& other) {
	_name = new char[strlen(other._name) + 1];
	strcpy_s(_name, strlen(other._name) + 1, other._name);
	_employeeCount = other._employeeCount;
}

Company::~Company() {
	delete[] _name;
}

const char* Company::getName() const {
	return _name;
}

Company& Company::setName(const char* name) {
	delete[] _name;
	_name = new char[strlen(name + 1)];
	strcpy_s(_name, strlen(name) + 1, name);

	return *this;
}

int Company::getEmployeeCount() const {
	return _employeeCount;
}

Company& Company::setEmployeeCount(int employeeCount) {
	_employeeCount = employeeCount;
	return *this;
}

Company& Company::operator=(const Company& other) {
	if (this != &other) {
		delete[] _name;
		_name = new char[strlen(other._name + 1)];
		strcpy_s(_name, strlen(other._name) + 1, other._name);
		_employeeCount = other._employeeCount;
	}
	return *this;
}

Company Company::operator+(const Company& other) const {
	char* temp = new char[strlen(_name) + strlen(other._name) + 2];
	sprintf_s(temp, strlen(temp), "%s %s", _name, other._name);
	return Company(temp, _employeeCount + other._employeeCount);
}

Company Company::operator-(int count) const {
	return Company(_name, _employeeCount - count);
}

Company Company::operator*(int percent) const {
	return Company(_name, _employeeCount + ((_employeeCount / 100.0) * percent));
}

std::ostream& operator<<(std::ostream& out, const Company& c) {
	out << c.getName() << ", " << c.getEmployeeCount();
	return out;
}

int main() {
	Company c("MArto", 4);
	Company c2("asdf", 3);
	cout << c + c2 << endl;
	cout << c - 2 << endl;
	cout << c * 25 << endl;
}