#include "ClothingShop.h"

ClothingShop::ClothingShop()
	: Company(), clothesCount(0), clothes(NULL)
{
	std::cout << "ClothingShop default constructor" << std::endl;
}

ClothingShop::ClothingShop(int employeeCount, Employee* employees,
	double overheadCosts, int clothesCount, Clothes* clothes)
	: Company(employeeCount, employees, overheadCosts), clothesCount(clothesCount),
	clothes(new Clothes[clothesCount])
{
	for (int i = 0; i < clothesCount; ++i)
		this->clothes[i] = clothes[i];
	std::cout << "ClothesShop constructor" << std::endl;
}

ClothingShop::ClothingShop(const ClothingShop& other)
	: Company(other), clothesCount(other.clothesCount), clothes(new Clothes[other.clothesCount])
{
	for (int i = 0; i < other.clothesCount; ++i)
		this->clothes[i] = other.clothes[i];
	std::cout << "ClothesShop copy constructor" << std::endl;
}

ClothingShop::~ClothingShop() {
	if (clothes != NULL) delete[] clothes;
	std::cout << "ClothingShop destructor" << std::endl;
}

ClothingShop& ClothingShop::operator=(const ClothingShop& other) {
	if (this != &other) {
		Company::operator=(other);
		clothesCount = other.clothesCount;
		if (clothes != NULL) delete[] clothes;
		clothes = new Clothes[other.clothesCount];
		for (int i = 0; i < other.clothesCount; ++i)
			clothes[i] = other.clothes[i];
	}
	return *this;
}

ClothingShop& ClothingShop::setClothes(Clothes* clothes, int clothesCount) {
	if (this->clothes != NULL) delete[] this->clothes;
	this->clothesCount = clothesCount;
	this->clothes = new Clothes[clothesCount];
	for (int i = 0; i < clothesCount; ++i)
		this->clothes[i] = clothes[i];
	return *this;
}

int ClothingShop::getClothesCount() const {
	return clothesCount;
}

const Clothes* ClothingShop::getClothes() const {
	return clothes;
}

double ClothingShop::costs() const {
	double sum = 0.;
	for (int i = 0; i < clothesCount; ++i)
		sum += clothes[i].getDeliveryPrice();
	return Company::costs() + sum;
}