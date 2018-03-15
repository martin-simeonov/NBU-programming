#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_PRIME 100000007

bool primes[MAX_PRIME];

void findPrimes(unsigned long long n) {
    unsigned long long j, i = 2;
    while (i <= n) {
        if(!primes[i]) {
            j = i * i;
            while (j <= n) {
                primes[j] = i;
                j += i;
            }
        }
        ++i;
    }
    primes[0] = true;
    primes[1] = true;
	primes[2] = false;
}

unsigned long acase(unsigned long a, unsigned long b) {
	unsigned long count = 0;
	for (unsigned long i = a; i <= b; ++i) {
		if (!primes[i]) ++count;
	}
	return count;
}

void bcase(unsigned long long k) {
	for (unsigned long long i = 0; i <= MAX_PRIME; ++i) {
		if (!primes[i]) {
			if ((k % i) == 0) {
				cout << i << endl;
                break;
			}
		}
	}
}

bool dcase(unsigned long long k) {
	unsigned long long remainder, reversedNumber = 0;

	while(k != 0) {
        remainder = k % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        k /= 10;
    }

	return !primes[reversedNumber];
}

void ecase(unsigned long k) {
	long long low = 0, high = 0;

	if (!primes[k]) {
		cout << k << endl;
		return;
	}

	for (unsigned long i = 0; i < k; ++i) {
		if (!primes[i]) low = i;
	}

	for (unsigned long i = k; i <= MAX_PRIME; ++i) {
		if (!primes[i]) {
			high = i;
			break;
		}
	}

	if (abs((long long) (low - k)) > abs((long long) (high - k))) {
		cout << high << endl;
	} else if (abs((long long) (low - k)) < abs((long long) (high - k))) {
		cout << low << endl;
	} else {
		cout << low << " " << high << endl;
	}
}

unsigned long fcase(unsigned long k) {
	unsigned long count = 0;
	for (int i = 0; i < k; ++i) {
		if (!primes[i]) ++count;
	}
	return count;
}

int main() {
    string line;
	char option;
	unsigned long a, b, k;

	findPrimes(MAX_PRIME);

    while(getline(cin,line)) {
		if (line == "quit") break;

		istringstream is(line);
		is >> option;

		switch(option) {
			case 'A':
            case 'a':
				is >> a; is >> b;
                if (b > MAX_PRIME)
                    b = MAX_PRIME;
                cout << acase(a, b) << endl; break;
			case 'B':
            case 'b':
				is >> k; bcase(k); break;
			case 'C':
            case 'c':
				is >> k; cout << !primes[k] << endl; break;
			case 'D':
            case 'd':
				is >> k; cout << dcase(k) << endl; break;
			case 'E':
            case 'e':
				is >> k; ecase(k); break;
			case 'F':
            case 'f':
				is >> k; cout << fcase(k) << endl; break;
		}
    }
}
