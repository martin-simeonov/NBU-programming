#include <iostream>
using namespace std;
#define MAXN 100000

int a[MAXN], c[MAXN], n;

void merge(int u, int v, int w) {
	int i, j, k;
    for(i = u, j = v + 1, k = 0; i <= v && j <= w; k++) {
		if(a[i] <=a [j]) c[k] = a[i++];
		else c[k] = a[j++];
	}
    if(i > v)
		for(i = j; i <= w; i++) c[k++] = a[i];
    else
		for(j = i; j <= v; j++) c[k++] = a[j];
    for(i = 0; i < k; i++) a[u + i] = c[i];
}

void  merge_sort(int p, int q) {
	if (p == q) return;
    merge_sort(p, (p + q) / 2);
    merge_sort((p + q) / 2 + 1, q);
    merge(p, (p + q) / 2, q);
}

int main() {
    int i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n - 1);
    for(i = 0; i < n; i++) cout << a[i] << endl;
    cout << endl;
}
