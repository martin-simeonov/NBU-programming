//http://www.geeksforgeeks.org/longest-common-subsequence/
#include <iostream>
using namespace std;

int lcs(string X, string Y, int m, int n ) {
   int L[m+1][n+1];
   int i, j;
   
   for (i=0; i<=m; i++) {
     for (j=0; j<=n; j++) {
		if (i == 0 || j == 0)
			L[i][j] = 0;
		else if (X[i-1] == Y[j-1])
			L[i][j] = L[i-1][j-1] + 1;
		else
			L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
   
   return L[m][n];
}

int main() {  
	string str1, str2;
	while (cin >> str1) {
		cin >> str2;
		
		int l = lcs(str1, str2, str1.length(), str2.length()); 
		cout << (str1.length() - l) + (str2.length() - l) << endl;
	}
}