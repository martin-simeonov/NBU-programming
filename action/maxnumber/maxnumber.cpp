//https://action.informatika.bg/problems/182

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int mlen = 0;

string operator*(const string& s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

string operator*(unsigned int n, const string& s) { return s * n; }

struct compare {
    bool operator() (string i, string j) {
        i = i * (mlen / i.length() + 1);
        j = j * (mlen / j.length() + 1);

        return i > j;
    }
} myCompare;

int main() {
    unsigned n;
    string num;
    vector<string> v;

    cin >> n;
    cin.ignore();
    while(cin >> num) v.push_back(num);

    for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
        if ((*it).length() > mlen) mlen = (*it).length();
    }
    mlen *= 2;

    sort(v.begin(), v.end(), myCompare);

    ostringstream oss("");
    for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
        oss << (*it);
    }
    cout << oss.str() << endl;
}
