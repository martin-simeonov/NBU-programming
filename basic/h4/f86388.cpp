#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, digit, size = 0;
    int *a, *newa;

    cin >> n;

    while (n > 0) {
        digit = n % 10;
        if (digit < 7) {
            newa = new int[size + 3];
        } else {
            newa = new int[size + 1];
        }
        memcpy(newa, a, size * sizeof(int));
        a = newa;

        if (digit < 7) {
            a[size++] = digit;
            a[size++] = digit + 7;
            a[size++] = digit * 7;
        } else {
            a[size++] = (7 - digit) * 3;
        }

        n /= 10;
    }

    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            cout << a[i] << endl;
        }
        delete [] a;
    }
}
