#include <iostream>
using namespace std;

int intersection(int a[], int b[], int c[], int n, int m) {
    int i, j, k;
    for(i = 0, j = 0, k = 0; i <= m && j <= n;)
        if (a[i] == b[j]) c[k++] = a[i++];
        else if (a[i] < b[j]) ++i;
        else j++;
    return k;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    int outArr[min(m, n)];
    int outSize = intersection(arr1, arr2, outArr, n, m);

    for (int i = 0; i < outSize; ++i) cout << outArr[i] << " ";
}
