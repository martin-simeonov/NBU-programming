#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 100

int main() {
    int n = MAX, m = MAX, v;
    srand((unsigned) time(NULL));

    cout << m << " " << n << endl;
    v = rand() % MAX + 1;

    for (int i = 1; i < m; ++i) {
        cout << v << " ";
        v += rand() % MAX + 1;
    }
    cout << v << endl;

    v = rand() % MAX + 1;

    for (int i = 1; i < n; ++i) {
        cout << v << " ";
        v += rand() % MAX + 1;
    }
    cout << v << endl;
}
