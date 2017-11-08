#include <iostream>
using namespace std;

int main() {
    int n, c, count = 0;

    cin >> n >> c;

    while(n > 0) {
        if ((n % 10) == c) ++count;
        n /= 10;
    }
    cout << count << endl;
}
