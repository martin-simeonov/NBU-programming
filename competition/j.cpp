#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v1, v2, v3;

void pascal(unsigned n, vector<long long> &v) {
	long long x = 1;
	for (long long k = 0; k <= n; ++k) {
		v.push_back(x);
		x = x * (n - k) / (k + 1);
	}
}

int main() {
    string line;
	int n, m, x = 0, k;
	int primeri;
	cin >> primeri;
	cin.ignore();

    while(x < primeri) {
		cin >> n >> m;
		cin >> k;
		pascal(n, v1);
		pascal(m, v2);
		v3.resize(m + n + 1);

		for (int i = 1; i <= (n + 1); ++i) {
			if ((i % 2) == 0) v1[i - 1] *= -1;
		}

		for (int i = 0; i <= n; i++) {
	    	for (int j = 0; j <= m; j++) {
	    		v3[i + j] += v1[i] * v2[j];
	    	}
	    }

		reverse(v3.begin(), v3.end());

		cout << v3[k]<< endl;
		x++;
		v1.clear();
		v2.clear();
		v3.clear();
	}
}
