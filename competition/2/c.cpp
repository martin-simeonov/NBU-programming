#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

struct Fraction {
    int n;
    int d;
};

int gcd(int a, int b) {
    int swap;
    while (b > 0) {
        swap = b;
        b = a % b;
        a = swap;
    }
    return a;
}

void add(Fraction &f, int a, int b, int c, int d) {
    int g;
    f.n = (a * d) + (b * c);
    f.d = b * d;
    g = gcd(f.n, f.d);
    f.n /= g;
    f.d /= g;
}

void sub(Fraction &f, int a, int b, int c, int d) {
    int g;
    f.n = (a * d) - (b * c);
    f.d = b * d;
    g = gcd(abs(f.n), abs(f.d));
	//cout << g << endl;
    f.n /= g;
    f.d /= g;
}

int main() {
    Fraction f;
    char ch;
	char sign;
    int a, b, c, d;
	string line;
	
	while(getline(cin,line)) {
        istringstream is(line);
		is >> a >> ch;
		if (ch == '/') {
			is >> b;
			is >> sign;
		} else {
			b = 1;
			sign = ch;
		}
		f.n = a;
		f.d = b;
		
		//cout << a << " " << b << endl;
		
		while (is >> a) {
			is >> ch;
			if (ch == '/') {
				is >> b;
			} else if (sign == '-') {
				//cout <<'h';
				sub(f, f.n, f.d, a, 1);
				sign = ch;
				continue;
			} else if (sign == '+') {
				//cout << "hrew";
				add(f, f.n, f.d, a, 1);
				sign = ch;
				continue;
			}
			//cout << a << " " << b << endl;
			
			if (sign == '+') {
				add(f, f.n, f.d, a, b);
			} else {
				sub(f, f.n, f.d, a, b);
			}
			is >> sign;
			ch = '\0';
		}
		
		cout << f.n;
        if (f.d > 1) cout << "/" << f.d;
        cout << endl;
	}
    return 0;
}