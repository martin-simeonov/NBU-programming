#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 5
#define M 5

// Function for testing
void print_matrix(int arr[][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        cout << '{';
        for (int k = 0; k < m; ++k) {
            cout << arr[i][k];
            if (k != m - 1) cout << '\t';
        }
        cout << '}' << endl;
    }
}

// 1. A)
void fill(int arr[][M], int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            arr[i][k] = rand() % 71 + 10;
        }
    }
}

// 1. B)
void matrix_modify(int arr[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((i + j) % 2 == 0) arr[i][j] = 10;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += arr[j][i];
        }
        cout << "Column " << i + 1 << " sum: " << sum << endl;
        sum = 0;
    }
}

// 2.
char* string_modify(char* str) {
    char buffer[5];
    unsigned cnt = 11, buffer_cnt = 0;
    bool digit_flag = false;

    char* out = new char(cnt);

    out[--cnt] = '\0';

    for (int i = 0; str[i] != '|'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            buffer[buffer_cnt++] = str[i];
            digit_flag = true;
        } else if (digit_flag) {
            for (int k = buffer_cnt - 1; k >= 0; --k) {
                out[--cnt] = buffer[k];
            }
            digit_flag = false;
            buffer_cnt = 0;

            if (cnt > 0)
                out[--cnt] = '-';
        } else {
            digit_flag = false;
        }
    }
    return out;
}

// 3.
int non_zero(int* arr, int n){
    if (n > 0) {
        if (arr[n - 1]) {
            return 1 + non_zero(arr, n - 1);
        } else {
            return non_zero(arr, n - 1);
        }
    }
    return 0;
}

int main() {
    int arr[N][M];

    cout << "1. A)" << endl;
    fill(arr, N, M);
    print_matrix(arr, N, M);

    cout << endl << "1. B)" << endl;
    matrix_modify(arr, N);

    cout << endl << "2." << endl;
    char str[] = "11.01.2018 | 09:15:35";
    cout << string_modify(str) << endl;

    cout << endl << "3." << endl;
    int A[] = {0, 1, 0, -6, 0, 6, 0, 0, 2, 2, 1};
    cout << "None zero elements:" << non_zero(A, 11) << endl;
}

