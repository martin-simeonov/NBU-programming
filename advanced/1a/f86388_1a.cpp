// f86388_1a.cpp
#include <iostream>
#include <string>
using namespace std;

int toDecimal(int base, string s)
{
    int m = 0;
    for (int i = 0; i < s.length(); i++) {
        m *= base;
        if (s[i] > 64)
            m += s[i] - '7';
        else
            m += s[i] - '0';
    }
    return m;
}

int main() {
    int base;
    string number;
    while (cin >> base) {
        cin >> number;
        cout << toDecimal(base,  number) << endl;
    }
    return 0;
}
