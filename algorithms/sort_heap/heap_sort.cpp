
#include <iostream>
using namespace std;

#define MAXN 10

int a[MAXN], sz;

void heapify(int i) {
    int j = i, left = 2 * i, right = 2 * i + 1;

    if (left <= sz && a[j] < a[left]) j = left;
    if (right <= sz && a[j] < a[right]) j = right;
    if (j != i) {
        swap(a[i], a[j]);
        heapify(j);
    }
}

void go_up(int i) {
    while (i != 1 && a[i] < a[i / 2]) {
        swap(a[i / 2], a[i]);
        i = i / 2;
    }
}

void make_heap() {
    for (int i = sz / 2; i >= 0; i--)
        heapify(i);
}



void sort() {
    sz = sz - 1;
    while (sz >= 1) {
        cout << a[0] << endl;
        a[0] = a[sz--];
        heapify(0);
    }
    cout << a[0] << endl;
}

int main() {
    int i, n;
    cin >> n;
    sz = n;
    for (i = 0; i < n; i++) cin >> a[i];
    make_heap();
    sort();
}
