#include "Clothes.h"

Clothes::Clothes()
	: Goods(), size(0)
{
	std::cout << "Clothes default constructor" << std::endl;
}

Clothes::Clothes(const char* name, double deliveryPrice, int size)
	: Goods(name, deliveryPrice), size(size)
{
	std::cout << "Clothes constructor" << std::endl;
}

Clothes::Clothes(const Clothes& other)
	: Goods(other), size(other.size)
{
	std::cout << "Clothes copy constructor" << std::endl;
}

Clothes::~Clothes() {
	std::cout << "Clothes destructor" << std::endl;
}

Clothes& Clothes::operator=(const Clothes& other) {
	if (this != &other) {
		Goods::operator=(other);
		size = other.size;
	}
	return *this;
}

Clothes& Clothes::setSize(int size) {
	this->size = size;
	return *this;
}

int Clothes::getSize() const {
	return size;
}