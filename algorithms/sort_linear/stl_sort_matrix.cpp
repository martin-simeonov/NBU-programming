#include <iostream>
#include <algorithm>
using namespace std;

int a[10][10], n, m;

bool mycmp(int i, int j) {
    int k = 0;
    cout << i << " " << j << endl;
    //for (k = 0; a[k][i] == a[k][j]; ++k);
    //return a[k][i] < a[k][j];
    return true;
}

int main() {
    int i, j;
    cin >> n >> m;
    for(i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> a[i][j];

    if(n != 1) sort(a[0], a[0] + n, mycmp);

    for (i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
