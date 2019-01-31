#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXN 100000

int a[MAXN], m1 = MAXN, n;

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
    srand(time(NULL));
    cout << m1 << endl;

    for (int i = 0; i < m1; ++i)
        a[i] = rand() % 100000;
    n = m1;
    bubble_sort();
    for (int i = 0; i < m1; ++i)
        cout << a[i] << endl;
}
