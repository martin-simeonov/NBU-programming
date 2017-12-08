#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

void print(const vector<string>& v) {
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    unsigned n;
    string line, num, max = "0";
    vector<string> v;

    cin >> n;
    cin.ignore();
    while(cin >> num) v.push_back(num);

    sort(v.begin(), v.end());
    do {
        num.clear();
        num = accumulate(v.begin(), v.end(), num);
        if (num > max) max = num;
    } while (next_permutation(v.begin(), v.end()));

    cout << max << endl;
}
