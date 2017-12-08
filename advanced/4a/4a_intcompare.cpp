#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator() (unsigned long long i, unsigned long long j) {
        ostringstream oss;
        oss << i << j;
        istringstream iss(oss.str());
        unsigned long long x, y;
        iss >> x;

        oss.clear();
        oss.str(std::string());

        oss << j << i;
        iss.clear();
        iss.str(oss.str());
        iss >> y;

        return x > y;
    }
} myCompare;

int main() {
    unsigned n;
    unsigned long long num;
    vector<unsigned long long> v;

    cin >> n;
    cin.ignore();
    while(cin >> num) v.push_back(num);

    sort(v.begin(), v.end(), myCompare);

    ostringstream oss("");
    for(vector<unsigned long long>::iterator it = v.begin(); it != v.end(); ++it) {
        oss << (*it);
    }
    cout << oss.str() << endl;
}
