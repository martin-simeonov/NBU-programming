#pragma once
#include <iostream>
#include <string>
using namespace std;

class Company {
	string _name;
	int _employeeCount;
public:
	Company();
	Company(string, int);

	string getName() const;
	int getEmployeeCount() const;
	Company& setName(string);
	Company& setEmployeeCount(int);

	virtual void showCapacity() const;

	virtual ostream& ext(ostream&) const;
	virtual istream& ins(istream&);
};

ostream& operator<<(ostream& out, const Company& c);
istream& operator>>(istream& in, Company& c);