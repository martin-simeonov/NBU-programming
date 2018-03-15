#include <iostream>
#include <iomanip>
using namespace std;

void print_triangle(int n, int m) {
    static int i = 1;
    if (n - 1 == m) return;
    for (int k = 0; k < i; ++k) {
        if (k == 0 || k == i - 1) cout << n;
        else cout << " ";
    }
    cout << endl;
    i++;
    n++;
    print_triangle(n, m);
}

int main() {
    print_triangle(2, 6);
}
