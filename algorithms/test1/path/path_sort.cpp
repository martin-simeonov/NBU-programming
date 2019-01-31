#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 100000

int a[MAXN];

bool compare_path(int ai1, int ai2) {
    //cout << ai1 << " " << ai2 << endl;
    //cout << "      " << abs((ai1 - a[0]) - (a[MAXN - 1] - ai1)) << endl;
    return abs((ai1 - a[0]) - (a[MAXN - 1] - ai1)) <= abs((ai2 - a[0]) - (a[MAXN - 1] - ai2));
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int low, int high) {
    int pivotIdx = high;    // pivot
    int i = (low - 1);  // Index of smaller element

    int t;

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (compare_path(a[j], a[pivotIdx])) {
            i++;    // increment index of smaller element
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;
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
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}
