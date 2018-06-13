#include "Company.h"
#include <cstring>

Company::Company()
	: _name(""), _employeeCount(0)
{}

Company::Company(string name, int employeeCount)
	: _name(name), _employeeCount(employeeCount)
{}

void Company::showCapacity() const {
	cout << "Employee count: " << _employeeCount << endl;
}

string Company::getName() const {
	return _name;
}

int Company::getEmployeeCount() const {
	return _employeeCount;
}

Company& Company::setName(string name) {
	_name = name;
	return *this;
}

Company& Company::setEmployeeCount(int count) {
	_employeeCount = count;
	return *this;
}

ostream& Company::ext(ostream& out) const {
	return out << "Name: " << _name << endl
		<< "Employee count: " << _employeeCount << endl;
}

istream& Company::ins(istream& in) {
	cout << "Enter name: ";
	getline(in, _name);
	cout << "Enter capacity: ";
	in >> _employeeCount;
	in.ignore();
	return in;
}

ostream& operator<<(ostream& out, const Company& c) {
	return c.ext(out);
}

istream& operator>>(istream& in, Company& c) {
	return c.ins(in);
}