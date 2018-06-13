#pragma once
#include <iostream>

class Goods {
	char* name;
	double deliveryPrice;
public:
	Goods();
	Goods(const char*, double);
	Goods(const Goods&);
	virtual ~Goods();

	Goods& operator=(const Goods&);
	
	Goods& setName(const char*);
	Goods& setDeliveryPrice(double);
	const char* getName() const;
	double getDeliveryPrice() const;
};