#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

#define MAXN 100000

int a[MAXN][2];

bool compare_fractions(int a, int b, int c, int d) {
    return a*d <= b*c;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int low, int high) {
    int pivotIdx = high;    // pivot
    int i = (low - 1);  // Index of smaller element

    int t1, t2;

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (compare_fractions(a[j][0], a[j][1], a[pivotIdx][0], a[pivotIdx][1])) {
            i++;    // increment index of smaller element
            t1 = a[i][0];
            t2 = a[i][1];
            a[i][0] = a[j][0];
            a[i][1] = a[j][1];
            a[j][0] = t1;
            a[j][1] = t2;
        }
    }
    t1 = a[i + 1][0];
    t2 = a[i + 1][1];
    a[i + 1][0] = a[high][0];
    a[i + 1][1] = a[high][1];
    a[high][0] = t1;
    a[high][1] = t2;
    return (i + 1);
}

/* The main function that implements QuickSort
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    char ch;
    int numerator, denominator, n;
    string line;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        getline(cin,line);
        istringstream is(line);
        is >> numerator >> ch;
        if (ch == '/')
            is >> denominator;
        a[i][0] = numerator;
        a[i][1] = denominator;
    }
    quickSort(0, n - 1);
    //cout << compare_fractions(9, 11, 100, 21);
    for (int i = 0; i < n; ++i) {
        cout << a[i][0] << "/" << a[i][1] << endl;
    }
    return 0;
}
