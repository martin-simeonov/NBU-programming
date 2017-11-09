#include <iostream>
#include <cmath>
#include <cstdlib>
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
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "is prime" << endl;
    } else {
        cout << "not prime" << endl;
    }

    int count;
    int n1;
    for (int i = 2; i <= 9; ++i) {
        count = 0;

        n1 = n;
        while (!(n1 % i)) {
            ++count;
            n1 /= i;
        }
        cout << i << " divides " << n << ", " << count << " times" << endl;
    }
}
