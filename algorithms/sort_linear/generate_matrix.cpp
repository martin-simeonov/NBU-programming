#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 1000

int main() {
    int n = 10, m = 10;
    srand(time(NULL));
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << rand() % (MAXN + 1) << " ";
        cout << endl;
    }
}
