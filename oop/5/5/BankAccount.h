#pragma once

class BankAccount {
	char* name;
	double balance;
	double limit;
public:
	BankAccount();
	BankAccount(const char*, double, double);
	BankAccount(const BankAccount&);
	~BankAccount();
	BankAccount& operator=(const BankAccount&);
	
	bool operator==(const BankAccount&) const;
	bool operator!=(const BankAccount&) const;
	BankAccount& operator+=(double);
	BankAccount& operator-=(double);
	BankAccount& operator*=(double);

	const char* getName() const;
	double getBalance() const;
	double getLimit() const;

	BankAccount& setName(const char*);
	BankAccount& setBalance(double);
	BankAccount& setLimit(double);
};