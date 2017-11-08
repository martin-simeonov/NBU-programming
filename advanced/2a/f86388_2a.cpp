// f86388_2a.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAX_PRIME 1000

bool primes[MAX_PRIME] = { false };

void findPrimes(unsigned n) {
    unsigned j, i = 2;
    while (i <= n) {
        if(!primes[i]) {
            j = i * i;
            while (j <= n) {
                primes[j] = true;
                j += i;
            }
        }
        ++i;
    }
    primes[0] = true;
    primes[1] = true;
}

int main() {
    unsigned count = 0, n, s;
    findPrimes(MAX_PRIME);
    while (cin >> s) {
        cin >> n;
        srand(s);
        for (int i = 0; i < n; ++i) {
            if (!primes[rand() % 1000]) ++count;
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}
