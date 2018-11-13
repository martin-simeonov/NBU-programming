#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n = 100000, m = 100000;
    srand(time(NULL));
    cout << n << endl;
    for (int i = 1; i <= n; ++i)
        cout << rand() % m + 1 << endl;
}
