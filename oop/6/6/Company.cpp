#include "Company.h"

Company::Company()
	: employeeCount(0), employees(NULL), overheadCosts(0.)
{
	std::cout << "Company default constructor" << std::endl;
}

Company::Company(int employeeCount, Employee* employees, double overheadCosts)
	: employeeCount(employeeCount), employees(new Employee[employeeCount]), 
	overheadCosts(overheadCosts)
{
	for (int i = 0; i < employeeCount; ++i)
		this->employees[i] = employees[i];
	std::cout << "Company constructor" << std::endl;
}

Company::Company(const Company& other)
	: employeeCount(other.employeeCount), employees(new Employee[other.employeeCount]),
	overheadCosts(other.overheadCosts)
{
	for (int i = 0; i < other.employeeCount; ++i)
		this->employees[i] = other.employees[i];
	std::cout << "Company copy constructor" << std::endl;
}

Company::~Company() {
	if (employees != NULL) delete[] employees;
	std::cout << "Company destructor" << std::endl;
}

Company& Company::operator=(const Company& other) {
	if (this != &other) {
		if (employees != NULL) delete[] employees;
		employeeCount = other.employeeCount;
		employees = new Employee[other.employeeCount];
		for (int i = 0; i < other.employeeCount; ++i)
			employees[i] = other.employees[i];
		overheadCosts = other.overheadCosts;
	}
	return *this;
}

Company& Company::setEmployees(Employee* employees, int employeeCount) {
	this->employeeCount = employeeCount;
	if (this->employees != NULL) delete[] employees;
	this->employees = new Employee[employeeCount];
	for (int i = 0; i < employeeCount; ++i)
		this->employees[i] = employees[i];
	return *this;
}

Company& Company::setOverheadCosts(double overheadCosts) {
	this->overheadCosts = overheadCosts;
	return *this;
}

int Company::getEmployeeCount() const {
	return employeeCount;
}

const Employee* Company::getEmployees() const {
	return employees;
}

double Company::getOverheadCosts() const {
	return overheadCosts;
}

double Company::costs() const {
	double sum = 0.;
	for (int i = 0; i < employeeCount; ++i)
		sum += employees[i].getSalary();
	return sum + overheadCosts;
}