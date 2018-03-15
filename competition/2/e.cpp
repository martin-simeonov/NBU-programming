#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <climits>
using namespace std;

size_t popcount(size_t n) {
    std::bitset<sizeof(size_t) * CHAR_BIT> b(n);
    return b.count();
}

struct compare {
    bool operator() (unsigned long long i, unsigned long long j) {
        unsigned long long a = i;
		unsigned long long b = j;
		size_t x = popcount(i);
		size_t y = popcount(j);
				
		if (x < y) {
			return true;
		} else if (x == y) {
			return a > b;
		} else {
			return false;
		}
    }
} myCompare;

int main() {
    unsigned n;
    unsigned long long num;
    vector<unsigned long long> v;
	string line;

	while(getline(cin,line)) {
		istringstream is(line);
		while(is >> num) v.push_back(num);

		sort(v.begin(), v.end(), myCompare);
		ostringstream oss("");
		for(vector<unsigned long long>::iterator it = v.begin(); it != v.end(); ++it) {
			oss << (*it) << " ";
		}
		cout << oss.str() << endl;
		v.clear();
	}
}