#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXN 10000000
#define K 1000000

int a[MAXN], N, b[K + 1];

int main() {
    int i, j, l = 0;

    for (i = 0; i <= K; ++i)
        b[i] = 0;

    for (i = 1; i <= MAXN; ++i) {
        b[rand() % K]++;
    }

    cout << MAXN << endl;

    for (i = 0; i <= K; ++i) {
        if (b[i] > 0) {
            for (j = 1; j <= b[i]; ++j) {
                a[l++] = i;
                cout << i << endl;
            }
        }
    }
}
