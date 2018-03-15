#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main() {
    string line;
    int n, max, min;
	long long k;
	
    while(getline(cin, line)) {
		min = 0;
		max = 0;
        istringstream(line) >> n;
        getline(cin, line);
		istringstream is(line);
		while(is >> k) v.push_back(k);

		for (int i = 1; i < n - 1; ++i) {
			if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
				++min;
				continue;
			}
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
				++max;
				continue;
			}
		}
		
		cout << min << " " << max << endl;
		v.clear();
	}
}