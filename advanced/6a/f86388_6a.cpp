//f86388_6a.cpp

#include <iostream>
#include <sstream>
using namespace std;

unsigned gcd(unsigned x, unsigned y) {
    unsigned tmp;
    while (y > 0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

void shiftLeft1(unsigned k, string m) {
    unsigned i, ths, next, gcdNK;
    unsigned n = m.length();
    char tmp;
    if (k > n) {
        k %= n;
    }

    for (gcdNK = gcd(n, k), i = 0; i < gcdNK; i++) {
        ths = i; tmp = m[ths];
        next = ths + k;
        if (next >= n)
            next -= n;
        while (next != i) {
            m[ths] = m[next];
            ths = next;
            next += k;
            if (next >= n)
                next -= n;
        }
        m[ths] = tmp;
    }
    cout << m << endl;
}

int main() {
    string m, line;
    unsigned k;

    while (getline(cin, m)) {
        getline(cin, line);
        istringstream is(line);
        while (is >> k) {
            shiftLeft1(k, m);
        }
    }
}
