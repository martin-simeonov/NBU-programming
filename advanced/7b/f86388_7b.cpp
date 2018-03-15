// http://www.geeksforgeeks.org/longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> arr, int n) {
    int i, j, max = 0;
    vector<int> lis(n, 1);

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];

    return max;
}

int main() {
    int n, num;
    vector<int> v;

    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> num;
            v.push_back(num);
        }

        cout << lis(v, n) << endl;
        v.clear();
    }
}
