#ifndef _COMPANY_H
#define _COMPANY_H

class Company {
	char* _name;
	int _employeeCount;
public:
	Company();
	Company(const char* name, int employeeCount);
	Company(const Company& other);
	~Company();

	const char* getName() const;
	Company& setName(const char* name);
	int getEmployeeCount() const;
	Company& setEmployeeCount(int employeeCount);

	Company& operator=(const Company& other);
	Company operator+(const Company& other) const;
	Company operator-(int count) const;
	Company operator*(int percent) const;
};

#endif
