#include "ClothingShop.h"
#include "SoftwareCompany.h"

int main() {
	Clothes clothes[3];
	
	clothes[0] = Clothes("shirt", 10, 40);
	clothes[1] = Clothes("pants", 15, 45);
	clothes[2] = Clothes("dress", 13, 30);
	
	Employee employees[2];
	employees[0] = Employee("E1", 1000);
	employees[1] = Employee("E2", 800);
	
	ClothingShop shop(2, employees, 200, 3, clothes);
	std::cout << shop.costs() << std::endl;
	
	SoftwareCompany softCompany(2, employees, 100, 1500);
	std::cout << softCompany.costs() << std::endl;
}