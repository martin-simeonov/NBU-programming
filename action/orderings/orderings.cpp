//https://action.informatika.bg/problems/145

#include <iostream>
using namespace std;

unsigned long factoriel(unsigned n) {
    unsigned i;
    unsigned long long r = 1;
    for (i = 2; i <= n; i++) r *= i;
    return r;
}

int main() {
    unsigned n, m;
    cin >> n >> m;

    unsigned long long s = 1;
    for (int i = m + 1; i <= (m+n); ++i) s *= i;
    cout << s / factoriel(n) << endl;
}
