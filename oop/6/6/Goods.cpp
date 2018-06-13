#include "Goods.h"

Goods::Goods()
	: name(NULL), deliveryPrice(0)
{
	std::cout << "Goods default constructor" << std::endl;
}

Goods::Goods(const char* name, double deliveryPrice)
	: name(new char[strlen(name) + 1]), deliveryPrice(deliveryPrice)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	std::cout << "Goods constructor" << std::endl;
}

Goods::Goods(const Goods& other)
	: name(new char[strlen(other.name) + 1]), deliveryPrice(other.deliveryPrice)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	std::cout << "Goods copy constructor" << std::endl;
}

Goods::~Goods() {
	if (name != NULL) delete[] name;
	std::cout << "Goods destructor" << std::endl;
}

Goods& Goods::operator=(const Goods& other) {
	if (this != &other) {
		if (name != NULL) delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		deliveryPrice = other.deliveryPrice;
	}
	return *this;
}

Goods& Goods::setName(const char* name) {
	if (this->name != NULL) delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

Goods& Goods::setDeliveryPrice(double deliveryPrice) {
	this->deliveryPrice = deliveryPrice;
	return *this;
}

const char* Goods::getName() const {
	return name;
}

double Goods::getDeliveryPrice() const {
	return deliveryPrice;
}