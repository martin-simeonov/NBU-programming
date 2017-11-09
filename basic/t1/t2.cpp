#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define N 12

int main() {
    int a[N];
    int n;
    int countOdd = 0;

    cout << "1." << endl;
    srand(time(NULL));
    for (int i = 0; i < N;) {
        n = (rand() % 89) + 10;
        if (n % 2 == 0) {
            if (countOdd < (N / 3)) {
                ++countOdd;
                a[i] = n;
                ++i;
            }
        } else {
            a[i] = n;
            ++i;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << "index " << i << ": " << a[i] << endl;
    }

    cout << endl << "2." << endl;
    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int k = 0; k < N; ++k) {
            if (a[i] == a[k]) ++count;
        }
        cout << "index: " << i << ", val: " << a[i] << ", count: " << count << endl;
    }

    cout << endl << "3." << endl;
    int r[8];
    int firstHalf = 0;
    int secondHalf = 0;
    for (int i = 0; i < 8; ++i) {
        r[i] = a[rand() % N];
        cout << "rand " << i << ": " << r[i] << endl;
        for (int k = 0; k < N; ++k) {
            if (r[i] == a[k]) {
                if (k < N/2) {
                    ++firstHalf;
                } else {
                    ++secondHalf;
                }
            }
        }
    }
    cout << "in index(0, " << N/2 << ")" << firstHalf << endl;
    cout << "in index(" << N/2 << "," << N << ")" << secondHalf << endl;
}
