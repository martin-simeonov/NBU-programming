//f86388_1.cpp

#include <iostream>
using namespace std;

void array_init(int **a, int n) {
    for (int k = n; k > 0; --k) {
        for (int i = k, j = 0; i < n; ++i, ++j) {
            a[i][j] = k;
        }
        for (int i = 0, j = k; j < n; ++i, ++j) {
            a[i][j] = k;
        }
    }
}

int main() {
    int n = 8;

    int **a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int [n];
    }

    array_init(a, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete [] a[i];
    }
    delete [] a;
}
