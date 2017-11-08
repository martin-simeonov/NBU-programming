#include <iostream>
#include <string>
using namespace std;

string changeNumeralSystem(unsigned n, unsigned base) {
    if (n == 0) return "0";

    string converted;

    while (n >= 1) {
        converted = static_cast<char>((n % base) + '0') + converted;
        n /= base;
    }
    return converted;
}

int main() {
	unsigned base;
	unsigned decimal;

	cout << "Numeral system base:";
	cin >> base;
    if (base < 2 || base > 9) {
        cout << "wrong base argument" << endl;
        return 0;
    }

	cout << "Decimal:";
	cin >> decimal;

    cout << decimal << "(10)=" << changeNumeralSystem(decimal, base)
        << "(" << base << ")" << endl;
}
