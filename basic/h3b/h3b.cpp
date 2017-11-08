#include <iostream>
using namespace std;

int main() {
    int n, sumPositive = 0, sumNegative = 0;

    while (cin >> n && n != 0) {
        if (n > 0) {
            sumPositive += n;
        } else {
            sumNegative += n;
        }
    }
    cout << sumNegative << ',' << sumPositive << endl;
}
