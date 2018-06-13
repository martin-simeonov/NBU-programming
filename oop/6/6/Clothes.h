#pragma once

#include "Goods.h"

class Clothes : public Goods {
	int size;
public:
	Clothes();
	Clothes(const char *, double, int);
	Clothes(const Clothes&);
	virtual ~Clothes();

	Clothes& operator=(const Clothes&);

	Clothes& setSize(int);
	int getSize() const;
};