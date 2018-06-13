#include "Employee.h"

Employee::Employee()
	: name(NULL), salary(0)
{
	std::cout << "Employee default constructor" << std::endl;
}

Employee::Employee(const char* name, double salary)
	: name(new char[strlen(name) + 1]), salary(salary)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	std::cout << "Employee constructor" << std::endl;
}

Employee::Employee(const Employee& other)
	: name(new char[strlen(other.name) + 1]), salary(other.salary)
{
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	std::cout << "Employee copy constructor" << std::endl;
}

Employee::~Employee() {
	if (name != NULL) delete[] name;
	std::cout << "Employee destructor" << std::endl;
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		if (name != NULL) delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		salary = other.salary;
	}
	return *this;
}

Employee& Employee::setName(const char* name) {
	if (this->name != NULL) delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

Employee& Employee::setSalary(double salary) {
	this->salary = salary;
	return *this;
}

const char* Employee::getName() const {
	return name;
}

double Employee::getSalary() const {
	return salary;
}