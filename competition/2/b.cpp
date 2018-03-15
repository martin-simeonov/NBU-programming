#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int square(string str, int k) {
	int count[26] = {0};
	int sq = 0;
	int max = 0;
	
	for (int i = 0; i < str.length(); ++i) {
		++count[str[i] - 'a'];
	}
	
	sort(count, count + 26);
	reverse(count, count + 26);
	for (int i = 0; i < 26; ++i) {
		sq += count[i] * count[i];
	}
	if (sq > max) max = sq;
	sq = 0;
	
	/*
	for (int i = 0; i < 25; ++i) {
		cout << count[i] << endl;
	}*/
	
	while (k > 0) {	
		count[0] += count[1];
		count[1] = 0;
		
		sort(count, count + 26);
		reverse(count, count + 26);
		
		for (int i = 0; i < 26; ++i) {
			sq += count[i] * count[i];
		}
		if (sq > max) max = sq;
		sq = 0;
		
		--k;
	}

	return max;
}

int main() {
	string line, str1;
	int num;
	
	while(getline(cin,line)) {
		istringstream is(line);
		is >> str1;
		is >> num;
		
		cout << square(str1, num) << endl;
	}
}