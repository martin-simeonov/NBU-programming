#include <iostream>
using namespace std;

#define MAXN 10000000

int a[MAXN], x;

int bin_search(int L, int R) {
    if (L > R) return -1;
    int k = (L + R) / 2;
    if (a[k] == x) return k;
    if (x < a[k])
        return bin_search(L, k - 1);
    return bin_search(k + 1, R);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    cout << bin_search(0, n) << endl;
}
