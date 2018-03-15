//f86388_2.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

void random_init(int **a, int n, int k) {
    int i, j, count = 0;
    srand(time(NULL));

    do {
        i = rand() % n;
        j = rand() % n;
        ++a[i][j];
        ++count;
    } while (a[i][j] < k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "iterations: " << count << endl;
}

int main() {
    int n = 8;

    int **a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int [n];
    }

    random_init(a, n, 3);

    for (int i = 0; i < n; ++i) {
        delete [] a[i];
    }
    delete [] a;
}
