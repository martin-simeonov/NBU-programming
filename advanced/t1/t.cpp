#include <iostream>
using namespace std;

unsigned no_gcd(unsigned a, unsigned b){
	return (0==b) ? a : no_gcd(b, a/b);}

int main() {
	cout << no_gcd(8, 24) << endl;
}
