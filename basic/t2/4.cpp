#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int N = 3;
const int M = 3;

void fill(int arr[][M], int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            arr[i][k] = rand() % 10;
        }
    }
}

void print_matrix(int arr[][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            cout << setw(2) << arr[i][k] << " ";
        }
        cout << endl;
    }
}

int sum(int arr[][M], int n, int m, int i, int cur_sum) {
    if (i == n) return cur_sum;
    for (int j = 0; j < m; ++j)
        cur_sum += arr[i][j];
    return sum(arr, n, m, i + 1, cur_sum);
}

int main() {
    int arr[N][M];

    fill(arr, N, M);
    print_matrix(arr, N, M);
    cout << sum(arr, N, N, 0, 0) << endl;
}
