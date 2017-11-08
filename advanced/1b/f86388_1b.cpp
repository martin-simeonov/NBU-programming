// f86388_1b.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool isPrime(unsigned n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); ++i) {
        if ((n % i) == 0) return false;
    }
    return true;
}

int main() {
    unsigned count = 0, n;
    while (cin >> n) {
        srand(n);
        for (int i = 0; i < 10000; ++i) {
            if (isPrime(rand() % 10000)) ++count;
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}
