#pragma once

#include "Company.h"

class SoftwareCompany : public Company {
	double rentalCosts;
public:
	SoftwareCompany();
	SoftwareCompany(int, Employee*, double, double);
	SoftwareCompany(const SoftwareCompany&);
	virtual ~SoftwareCompany();

	SoftwareCompany& operator=(const SoftwareCompany&);

	SoftwareCompany& setRentalCosts(double);
	double getRentalCosts() const;

	virtual double costs() const;
};