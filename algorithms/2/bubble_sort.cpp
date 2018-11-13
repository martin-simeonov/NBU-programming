#include <iostream>
using namespace std;
#define MAXN 100000

int a[MAXN], n;

void bubble_sort() {
    int i, j, t;
    for(i = n - 2; i >= 0; i--)
        for(j = 0; j <= i; j++)
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main() {
    int i;
    cin>>n;
    for(i = 0; i < n; i++) cin >> a[i];
    bubble_sort();
    for(i = 0;i < n; i++) cout << a[i] << " ";
    cout << endl;

}
