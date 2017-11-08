// f12345_0a.cpp
#include <iostream>
#include <string>
using namespace std;

string ten2two(int n)
{
       string m;
       while (n >= 1)
       {
             m = static_cast<char>((n%2) + '0') + m;
             n /=2;
       }
       return m;
}

int two2ten(string s)
{
    int m = 0;
    for (int i = 0; i < s.length(); i++) m = 2*m + (s[i] - '0');
    return m;
}

int main()
{
    int k, n;
    string s;
    while (cin >> k)
    {     if (k==2) cin >> s; else cin >> n;
//          cout << k << " " << s << endl;
          if (k==10) cout << 2 << " " << ten2two(n);
          else cout << 10 << " " << two2ten(s);
          cout << endl;
    }
    return 0;
}
