#include "Company.h"
#include "Shop.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("test.txt");

	Shop s[5];
	for (int i = 0; i < 5; ++i) {
		s[i].setName("shop" + to_string(i + 1));
		s[i].setEmployeeCount(i + 1);
		s[i].setGoodsCount(i + 11);
		s[i].setPrice(1.5 + i);
		s[i].setShopArea(10.0 + (i + 1));
		myfile << s[i] << endl;
	}
	myfile.close();
	
	string line;
	ifstream infile("test.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			cout << line << endl;
		}
		infile.close();
	}

	try {
		s[0].sellGoods(15);
	}
	catch (InsufficientNumberOfGoodsException) {

	}
}