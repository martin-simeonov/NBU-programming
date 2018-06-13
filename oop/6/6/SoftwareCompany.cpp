#include "SoftwareCompany.h"

SoftwareCompany::SoftwareCompany()
	: Company(), rentalCosts(0.)
{
	std::cout << "SoftwareCompany default constructor" << std::endl;
}

SoftwareCompany::SoftwareCompany(int employeeCount, Employee* employees,
	double overheadCosts, double rentalCosts)
	: Company(employeeCount, employees, overheadCosts), rentalCosts(rentalCosts)
{
	std::cout << "SoftwareCompany constructor" << std::endl;
}

SoftwareCompany::SoftwareCompany(const SoftwareCompany& other)
	: Company(other), rentalCosts(other.rentalCosts)
{
	std::cout << "SoftwareCompany copy constructor" << std::endl;
}

SoftwareCompany::~SoftwareCompany() {
	std::cout << "SoftwareCompany destructor" << std::endl;
}

SoftwareCompany& SoftwareCompany::operator=(const SoftwareCompany& other) {
	if (this != &other) {
		Company::operator=(other);
		rentalCosts = other.rentalCosts;
	}
	return *this;
}

SoftwareCompany& SoftwareCompany::setRentalCosts(double rentalCosts) {
	this->rentalCosts = rentalCosts;
	return *this;
}

double SoftwareCompany::getRentalCosts() const {
	return rentalCosts;
}

double SoftwareCompany::costs() const {
	return Company::costs() + rentalCosts;
}