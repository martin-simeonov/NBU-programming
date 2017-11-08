// f86388_2b.cpp
#include <iostream>
using namespace std;

struct Fraction {
    unsigned n;
    unsigned d;
};

unsigned gcd(unsigned a, unsigned b) {
    unsigned swap;
    while (b > 0) {
        swap = b;
        b = a % b;
        a = swap;
    }
    return a;
}

Fraction add(unsigned a, unsigned b, unsigned c, unsigned d) {
    Fraction f;
    unsigned g;
    f.n = (a * d) + (b * c);
    f.d = b * d;
    g = gcd(f.n, f.d);
    f.n /= g;
    f.d /= g;
    return f;
}

int main() {
    Fraction fraction;
    char ch;
    unsigned a, b, c, d;
    while (cin >> a >> ch >> b >> ch >> c >> ch >> d) {
        fraction = add(a, b, c, d);
        cout << fraction.n;
        if (fraction.d > 1) cout << "/" << fraction.d;
        cout << endl;
    }
    return 0;
}
