#include "BankAccount.h"
#include <cstring>
#include <iostream>
using namespace std;

BankAccount::BankAccount()
	:name(NULL), balance(0), limit(0)
{}

BankAccount::BankAccount(const char* name, double balance, double limit)
	:name(new char[strlen(name) + 1]), balance(balance), limit(limit)
{
	strcpy_s(this->name, strlen(name) + 1, name);
}

BankAccount::BankAccount(const BankAccount& other)
	:name(new char[strlen(other.name) + 1]), balance(other.balance), limit(other.limit)
{
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
}

BankAccount::~BankAccount() {
	delete[] name;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
	if (this != &other) {
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		balance = other.balance;
		limit = other.limit;
	}
	return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {
	if (strcmp(name, other.name) == 0 &&
		balance == other.balance &&
		limit == other.limit)
	{
		return true;
	}
	return false;
}

bool BankAccount::operator!=(const BankAccount& other) const {
	return	!(*this == other);
}

BankAccount& BankAccount::operator+=(double amount) {
	balance += amount;
	return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
	balance -= amount;
	return *this;
}

BankAccount& BankAccount::operator*=(double percent) {
	balance += (balance / 100) * percent;
	return *this;
}

const char* BankAccount::getName() const {
	return name;
}

double BankAccount::getBalance() const {
	return balance;
}

double BankAccount::getLimit() const {
	return limit;
}

BankAccount& BankAccount::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

BankAccount& BankAccount::setBalance(double balance) {
	this->balance = balance;
	return *this;
}

BankAccount& BankAccount::setLimit(double limit) {
	this->limit = limit;
	return *this;
}

int main() {
	BankAccount b;
	b.setName("marto");
	b.setBalance(2);
	b.setLimit(2);
	BankAccount b2(b);

	cout << (b == b2) << endl;
	b += 3;
	b -= 3;
	cout << (b != b2) << endl;
	cout << b2.getName() << endl;
	b *= 50;
	cout << b.getBalance() << endl;
	b2 = b;
}
