#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string line;
    int i=0;
	int primeri;
	
	vector<int> v;
	
	cin >> primeri;
	cin.ignore();
	
    while(i < primeri) {
		getline(cin,line);
		
		v.push_back(count(line.begin(), line.end(), 'B') + count(line.begin(), line.end(), 'b'));
		v.push_back((count(line.begin(), line.end(), 'A') + count(line.begin(), line.end(), 'a')) / 2);
		v.push_back(count(line.begin(), line.end(), 'Z') + count(line.begin(), line.end(), 'z'));
		v.push_back(count(line.begin(), line.end(), 'I') + count(line.begin(), line.end(), 'i'));
		v.push_back(count(line.begin(), line.end(), 'N') + count(line.begin(), line.end(), 'n'));
		v.push_back(count(line.begin(), line.end(), 'G') + count(line.begin(), line.end(), 'g'));
		
		sort(v.begin(), v.end());

		cout << v[0] << endl;
		++i;
		v.clear();
	}
}