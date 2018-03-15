//f86388_3.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

void random_init_count(int **a, int n, int k) {
    int i, j, count = 0, iterations = 0;
    srand(time(NULL));

    do {
        i = rand() % n;
        j = rand() % n;
        if (!a[i][j]) {
            ++count;
            a[i][j] = 1;
        }
        ++iterations;
    } while (count < k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "iterations: " << iterations << endl;
}

int main() {
    int n = 8;

    int **a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int [n];
    }

    random_init_count(a, n, 16);

    for (int i = 0; i < n; ++i) {
        delete [] a[i];
    }
    delete [] a;
}
