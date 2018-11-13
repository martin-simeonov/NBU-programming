#include <iostream>
using namespace std;
#define MAX 1000

int a[MAX], m, b[MAX], n, c[2 * MAX];

void merge() {
	int i, j, k;
    for(i = 0, j = 0, k = 0; i < m && j < n; k++)
		if(a[i] <= b[j]) c[k] = a[i++];
		else c[k] = b[j++];
	if(i == m)
		for(i = j; i < n; i++) c[k++] = b[i];
    else
		for(j = i; j < m; j++) c[k++] = a[j];
}


int main() {
    int i;
    cin >> m >> n;
    for(i = 0; i < m; i++) cin >> a[i];
	for(i = 0; i < n; i++) cin >> b[i];
	merge();
    for(i = 0; i < m + n; i++) cout << c[i] << endl;
    cout << endl;
}
