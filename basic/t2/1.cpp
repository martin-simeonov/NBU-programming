#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 5;
const int M = 5;


// 1. A)
void fill(int arr[][M], int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            arr[i][k] = rand() % 80 + 10;
        }
    }
}
/*
int max_row(int arr[][M], int n, int m) {
    int max_sum = 0;
    int max_sum_index = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) sum += arr[i][k];
        if (sum > max_sum) {
            max_sum = sum;
            max_sum_index = i;
        }
        sum = 0;
    }
    return max_sum_index;
}

void main_diagonal(int arr[][M], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i][i];
    }
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            if ((arr[i][k] % 2) == 0) arr[i][k] += sum;
        }
    }
}

bool prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if ((n % i) == 0) return false;
    }
    return true;
}

void print_prime(int arr[][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            if (prime(arr[i][k])) cout << arr[i][k] << endl;
        }
    }
}
*/
void print_matrix(int arr[][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            cout << setw(2) << arr[i][k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[N][M];

    fill(arr, N, M);
    print_matrix(arr, N, M);
/*    cout << max_row(arr, N, M) << endl;
    main_diagonal(arr, N, M);
    print_matrix(arr, N, M);
    print_prime(arr, N, M);*/
}

