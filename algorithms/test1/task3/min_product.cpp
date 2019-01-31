#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int positive[MAXN], negative[MAXN];

bool mycmp(int i, int j) {
    return i < j;
}

int main() {
    int i, j = 0, k = 0, num, n;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) {
            positive[j++] = num;
        } else if (num < 0) {
            negative[k++] = num;
        }
    }

    sort(positive, positive + j);
    if (k > 1) sort(negative, negative + k);

    long long res = 0;

    if (k >= 1 && j >= 1) {
        res = negative[0];
        res *= positive[j - 1];
        cout << res;
    } else if (k >= 1) {
        res = negative[k - 1];
        res *= negative[k - 2];
        cout << res;
    } else {
        res = positive[0];
        res *= positive[1];
        cout << res;
    }

    cout << endl;
}
