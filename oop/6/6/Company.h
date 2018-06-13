#pragma once

#include "Employee.h"

class Company {
	int employeeCount;
	Employee* employees;
	double overheadCosts;
public:
	Company();
	Company(int, Employee*, double);
	Company(const Company&);
	virtual ~Company();

	Company& operator=(const Company&);

	Company& setEmployees(Employee*, int);
	Company& setOverheadCosts(double);
	int getEmployeeCount() const;
	const Employee* getEmployees() const;
	double getOverheadCosts() const;

	virtual double costs() const;
};