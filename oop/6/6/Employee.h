#pragma once

#include <iostream>

class Employee {
	char* name;
	double salary;
public:
	Employee();
	Employee(const char*, double);
	Employee(const Employee&);
	virtual ~Employee();

	Employee& operator=(const Employee&);

	Employee& setName(const char*);
	Employee& setSalary(double);
	const char* getName() const;
	double getSalary() const;
};