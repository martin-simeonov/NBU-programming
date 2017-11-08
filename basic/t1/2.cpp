#include <iostream>
using namespace std;

int main() {
    double a, d, sum = 0;
    int n;

    cin >> a >> d >> n;
    double a1 = a;

    for (int i = 0; i <= n; ++i) {
        sum += a;
        a += d;
    }

    cout << sum << endl;
}
