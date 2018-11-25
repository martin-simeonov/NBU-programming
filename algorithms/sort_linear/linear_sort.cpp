#include <iostream>
using namespace std;

#define MAXN 1000000
#define K 100000

int a[MAXN], N, b[K + 1];

int main() {
    int i, j, l = 0;
    cin >> N;

    for (i = 0; i <= K; ++i)
        b[i] = 0;

    for (i = 1; i <= N; ++i) {
        cin >> j;
        b[j]++;
    }

    for (i = 0; i <= K; ++i) {
        if (b[i] > 0) {
            for (j = 1; j <= b[i]; ++j) {
                a[l++] = i;
                cout << i << endl;
            }
        }
    }
}
