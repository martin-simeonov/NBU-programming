#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned long long> v;

int main() {
    string line;
    int i=0;
	unsigned long long k;
	int primeri, n;
	cin >> primeri;
	cin.ignore();
	
    while(i < primeri) {
		cin >> n;
		cin.ignore();
		cin.ignore();
        getline(cin,line);
		istringstream is(line);
        while(is >> k) v.push_back(k);

		i++;
		
		sort(v.begin(), v.end());
		/*for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			cout << (*it) << " ";
		}*/
		if ((n % 2) != 0) {
			cout << v[n/2] << endl;
		} else {
			cout << v[(n/2)-1] << endl;
		}
		v.clear();
    }
}