#pragma once
#include "Company.h"

class Shop: public Company {
	int goodsCount;
	double price;
	double shopArea;


public:
	Shop();
	Shop(string, int, int, double, double);

	int getGoodsCount() const;
	double getPrice() const;
	double getShopArea() const;

	Shop& setGoodsCount(int);
	Shop& setPrice(double);
	Shop& setShopArea(double);

	virtual void showCapacity() const;

	virtual ostream& ext(ostream&) const;
	virtual istream& ins(istream&);

	void sellGoods(int);
};

class InsufficientNumberOfGoodsException {

};