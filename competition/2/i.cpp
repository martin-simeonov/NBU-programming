//http://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isFeasible(int mid, vector<int> arr, int n, int k) {
    int pos = arr[0];
    int elements = 1;
 
    for (int i=1; i<n; i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
			
            if (elements == k)
              return true;
        }
    }
    return 0;
}

int largestMinDist(vector<int> arr, int n, int k) {
    sort(arr.begin(), arr.end());
 
    int res = -1;
    int left = arr[0], right = arr[n-1];
 
    while (left < right) {
        int mid = (left + right)/2;
 
        if (isFeasible(mid, arr, n, k)) {
            res = max(res, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }
 
    return res;
}

int main() {
	vector<int> v;
	
	int x, n, k, num;
	cin >> x;
	for (int i = 0; i < x; ++i) {
		cin >> n >> k;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			v.push_back(num);
		}
		cout << largestMinDist(v, n, k) << endl;
		v.clear();
	}
    return 0;
}