#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int u[MAXN];

int main() {
    int m, n, num, i, uSize;

    cin >> m >> n >> uSize;

    for (i = 0; i < uSize; ++i) u[i] = 0;

    for (i = 0; i < m; ++i) {
        cin >> num;
        u[num] += 1;
    }
    int nmax;
    for (i = 0; i < n; ++i) {
        cin >> num;
        u[num] += 1;
        if (num > nmax) nmax = num;
    }

    bool print = false;
    for (i = 1; i < nmax; ++i) {
        if (u[i] == 0) {
            cout << i << " ";
            print = true;
        }
    }
    if (!print) {
        cout << "Empty";
    }
    cout << endl;
}
