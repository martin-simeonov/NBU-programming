// http://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void distribute(vector<int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    for (int j = (sum / 2); j >= 0; j--) {
        if (dp[n][j] == true) {
            cout << j << " " << sum - j<< endl;
            break;
        }
    }
}

int main() {
    int num;
    string line;
    vector<int> v;

    while (getline(cin, line)) {
        istringstream iss(line);
        while (iss >> num) v.push_back(num);

        distribute(v, v.size());
        v.clear();
    }
}
