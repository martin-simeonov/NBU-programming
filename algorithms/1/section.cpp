#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    for (int i = 0; i < n; ++i) cout << arr1[i] << " ";
    for (int i = 0; i < m; ++i) cout << arr2[i] << " ";
}
