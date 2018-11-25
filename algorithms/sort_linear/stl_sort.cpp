#include <iostream>
#include <algorithm>
using namespace std;

int a[1000000], n;

bool mycmp(int i, int j) {
    return i < j;
}

int main() {
    int i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];

    if(n != 1) sort(a, a + n, mycmp);

    for(i = 0; i < n; i++) cout << a[i] << endl;
}
