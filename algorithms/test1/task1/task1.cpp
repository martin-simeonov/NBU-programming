#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

#define MAXN 500000

int res[MAXN];
int even[MAXN];
int odd[MAXN];

int partition (int a[], int low, int high, bool order) {
    int pivotIdx = high;
    int i = (low - 1);

    int t;

    for (int j = low; j <= high - 1; j++) {
        if (order) {
            if (a[j] <= a[pivotIdx]) {
                i++;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } else {
            if (a[j] > a[pivotIdx]) {
                i++;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

    }
    t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;
    return (i + 1);
}
void quickSort(int a[], int low, int high, bool order) {
    if (low < high) {
        int pi = partition(a, low, high, order);

        quickSort(a, low, pi - 1, order);
        quickSort(a, pi + 1, high, order);
    }
}

int main() {
    int n, num;
    int j = 0;
    int k = 0;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num % 2 == 0) even[j++] = num;
        else odd[k++] = num;
    }
    quickSort(even, 0, j - 1, true);
    for (int i = 0; i < j; ++i) {
        cout << even[i] << " ";
    }
    quickSort(odd, 0, k - 1, false);
    for (int i = 0; i < k; ++i) {
        cout << odd[i] << " ";
    }

    return 0;
}
