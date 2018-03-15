//f86388_6b.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool findMajority(vector<string> m, unsigned size, string &majority) {
    unsigned cnt, i;
    for (i = cnt = 0; i < size; i++) {
        if (0 == cnt) {
            majority = m[i];
            cnt = 1;
        }
        else if (m[i] == majority)
            cnt++;
        else
            cnt--;
    }
    if (cnt > 0) {
        for (i = cnt = 0; i < size; i++) {
            if (m[i] == majority)
                cnt++;
        }
        return (cnt > (size / 2));
    }
    return 0;
}

int main() {
    string str, line, majority;
    vector<string> sset;
    unsigned n;
    unsigned i = 0;

    while (cin >> n) {
        while (i < n) {
            cin >> str;
            sset.push_back(str);
            ++i;
        }

        if (findMajority(sset, n, majority)) {
            cout << majority << endl;
        } else {
            cout << "" << endl;
        }

        i = 0;
        sset.clear();
    }
}
