#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define EPSILON 0.00000000000000000001
#define F 86388

#define MAXN 1000

int param;

long double func(long double x) {
    return x*x*x*x*x - param*x*x - F % 100;
}

void bisection(long double a, long double b) {
    if (func(a) * func(b) >= 0) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    long long i = 0;
    long double c = a;
    while ((b - a) / 2 >= EPSILON && i < MAXN) {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (abs(func(c)) < EPSILON)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
        ++i;
    }
    cout << setprecision(20) << c << endl;
}

int main() {
    int n;

    while(cin >> n) {
        param = n;
        long double a = 0, b = 10;
        bisection(a, b);
    }
}
