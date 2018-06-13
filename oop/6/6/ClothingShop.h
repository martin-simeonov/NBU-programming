#pragma once

#include "Company.h"
#include "Clothes.h"

class ClothingShop : public Company {
	int clothesCount;
	Clothes* clothes;
public:
	ClothingShop();
	ClothingShop(int, Employee*, double, int, Clothes*);
	ClothingShop(const ClothingShop&);
	virtual ~ClothingShop();

	ClothingShop& operator=(const ClothingShop&);

	ClothingShop& setClothes(Clothes*, int);
	int getClothesCount() const;
	const Clothes* getClothes() const;

	virtual double costs() const;
};