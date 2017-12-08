#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	unsigned long a, b, v;
	unsigned long p = 0;
	int i = 0;
	
    while(cin >> a >> b >> v) {
		p = 0;
		for (i = 1;;++i) {
			p += a;
			if (p >= v) {
				break;
			}
			p -= b;
		}
		cout << i << endl;
	}
}