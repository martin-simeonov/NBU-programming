#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 100000

int main() {
    int n = 1000000;
    srand(time(NULL));
    cout << n << endl;
    for (int i = 1; i <= n; ++i)
        cout << rand() % (MAXN + 1) << endl;
}
