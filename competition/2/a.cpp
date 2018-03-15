#include <iostream>
#include<bits/stdc++.h>
using namespace std;

unsigned long long binomialCoeff(unsigned long long n, unsigned long long k)
{
    unsigned long long C[k+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
 
    for (unsigned long long i = 1; i <= n; i++)
    {
        for (unsigned long long j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

int main() {
    unsigned n, m;
	
	while(cin >> n >> m) {
		cout << binomialCoeff(n + m, m) << endl;
	}
}