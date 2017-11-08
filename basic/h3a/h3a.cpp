#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned n;
    char ch;

    cin >> n >> ch;

    for (int i = 0; i < n; ++i) {
        cout << setw(n-i);
        for (int k = 0; k <= i; ++k) {
            if (k == 0 || k == i || (i + 1) == n)
                cout << '*';
            else
                cout << ch;
        }
        cout << endl;
    }
}
