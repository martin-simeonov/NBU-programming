// https://www.geeksforgeeks.org/maximum-path-sum-triangle/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1024

//  Function for finding maximum sum
int maxPathSum(int tri[][MAXN], int m, int n)
{
     // loop for bottom-up calculation
     for (int i=m-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {
            // for each element, check both
            // elements just below the number
            // and below right to the number
            // add the maximum of them to it
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
     }

     // return the top element
     // which stores the maximum sum
     return tri[0][0];
}

/* Driver program to test above functions */
int main()
{
    int n;
    cin >> n;

    int tri[MAXN][MAXN];
    int row = 0;

    for (int i = 0; i < n; ++i) {
        string line;
        int k, j = 0;
        row = i;
        getline(cin,line);
        istringstream is(line);
        while(is >> k) tri[row++][j++] = k;
    }

   /* for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }*/

   cout << maxPathSum(tri, n, n) << endl;
   return 0;
}
