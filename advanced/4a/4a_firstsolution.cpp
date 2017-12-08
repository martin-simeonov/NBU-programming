#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned> digits(unsigned x){
    vector<unsigned> returnValue;
    while (x >= 10){
        returnValue.push_back(x % 10);
        x = x / 10;
    }
    returnValue.push_back(x);
    reverse(returnValue.begin(), returnValue.end());
    return returnValue;
}

struct compare {
    bool operator() (unsigned long long i, unsigned long long j) {
        vector<unsigned> iDigits = digits(i);
        vector<unsigned> jDigits = digits(j);

        unsigned n = max(iDigits.size(), jDigits.size());
        unsigned a, b;

        for (unsigned k = 0; k < n; ++k) {
            a = k >= iDigits.size() ? iDigits[iDigits.size() - 1] : iDigits[k];
            b = k >= jDigits.size() ? jDigits[jDigits.size() - 1] : jDigits[k];

            if (a != b) {
                return a > b;
            }
        }
        return false;
    }
} myCompare;

int main() {
    unsigned n;
    unsigned long long num;
    vector<unsigned long long> v;

    cin >> n;
    while(cin >> num) v.push_back(num);

    sort(v.begin(), v.end(), myCompare);

    ostringstream oss("");
    for(vector<unsigned long long>::iterator it = v.begin(); it != v.end(); ++it) {
        oss << (*it);
    }
    cout << oss.str() << endl;
}
