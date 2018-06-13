#include "Shop.h"

Shop::Shop()
	: Company(), goodsCount(0), price(0.), shopArea(0.)
{}

Shop::Shop(string name, int employeeCount, int goodsCount, double price, double shopArea)
	: Company(name, employeeCount), goodsCount(goodsCount), price(price), shopArea(shopArea)
{}

int Shop::getGoodsCount() const {
	return goodsCount;
}

double Shop::getPrice() const {
	return price;
}

double Shop::getShopArea() const {
	return shopArea;
}

Shop& Shop::setGoodsCount(int goods) {
	goodsCount = goods;
	return *this;
}

Shop& Shop::setPrice(double price) {
	this->price = price;
	return *this;
}

Shop& Shop::setShopArea(double area) {
	shopArea = area;
	return *this;
}

void Shop::showCapacity() const {
	Company::showCapacity();
	cout << "Shop area: " << shopArea << endl;
}

ostream& Shop::ext(ostream& out) const {
	Company::ext(out);
	return out << "Goods count: " << goodsCount << endl
		<< "Price: " << price << endl
		<< "Shop area: " << shopArea;
}

istream& Shop::ins(istream& in) {
	Company::ins(in);
	cout << "Enter goods count: ";
	in >> goodsCount;
	cout << "Enter price: ";
	in >> price;
	cout << "Enter shop area: ";
	in >> shopArea;
	in.ignore();
	return in;
}

void Shop::sellGoods(int count) {
	if ((goodsCount - count) < 0) throw InsufficientNumberOfGoodsException();
	else goodsCount -= count;
}