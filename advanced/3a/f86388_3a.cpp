#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int sumTarget;

bool found;

void checkSum() {
    int sum = 0;
    int swap;
    for (int i = 0; i < v.size(); ++i) sum += v[i];
    if (sum == sumTarget && v[0] > 0) {
        found = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > 0 && i > 0) cout << "+";
            cout << v[i];
        }
        cout << "=" << sum << endl;
    }
}

void variate(unsigned i) {
    if (found) return;
    if (i >= v.size()) {
        checkSum();
        return;
    }
    v[i] = abs(v[i]);
    variate(i + 1);

    v[i] = -abs(v[i]);
    variate(i + 1);
}

int main() {
    string line;
    int k;
    while(getline(cin,line)) {
        istringstream is(line);
        while(is >> k) v.push_back(k);

        found = false;
        if (v.size() == 1) {
            cout << v.back() << endl;
        } else {
            sumTarget = v.back();
            v.pop_back();
            variate(0);
            if (!found) cout << endl;
        }
        v.clear();
    }
}


