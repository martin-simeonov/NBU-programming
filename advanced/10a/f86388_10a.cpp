// f86388_10a.cpp
#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;

#define FN 86388

int main() {
    long long m, n, k;
    long long r;
    multiset<long long> sett;
    vector<long long> v;
    while (cin >> m >> n >> k) {
        //cout << m << " " << n << " " << k << endl;
        srand(FN % 100);
        for (long long i = 0; i < m; ++i) {
            r = rand() % k;
        //    cout << r << endl;
            sett.insert(r);
            if (sett.size() > n)  sett.erase(--sett.end());
        }

        for (set<long long>::iterator it = sett.begin(); it != sett.end(); ++it) {
            v.push_back(*it);
       //     cout << (*it) << " ";
        }
        cout << (*(v.end() - 1)) << endl;
        sett.clear();
        v.clear();
    }
}
