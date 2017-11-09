#include <iostream>
#include <cmath>
using namespace std;

double sum(int n, double x) {
    double sum1 = 0.0, sum2 = 0.0;

    for (int m = 1; m < n; ++m) {
        sum2 = 0.0;
        for (int k = 1; k <= m; ++k) {
            sum2 += (1 / k) * pow(x, m);
        }
        sum1 += pow(-1, m + 1) * sum2;
    }

    return sum1;
}

int main() {
    int n;
    double x;

    cin >> n >> x;

    cout << "sum " << sum(n, x) << endl;

    double s = log(1 + x) / (1 + x);
    cout << s << endl;

    n = 2;
    while(fabs(sum(n, x) - s) > 0.0001) {
        n += 1;
        if (n > 99) {
            break;
        }
    }
    cout << "value for n: " << n << endl;
}
