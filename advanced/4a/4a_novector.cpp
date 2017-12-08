#include <iostream>
#include <sstream>
using namespace std;

int mlen = 0;

string operator*(const string& s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

string operator*(unsigned int n, const string& s) { return s * n; }

bool compare(string i, string j) {
    i = i * (mlen / i.length() + 1);
    j = j * (mlen / j.length() + 1);

    return i > j;
}

void gnomeSort(string* array, int arrayLength) {
    for (int idx = 1; idx < arrayLength; idx++) {
        if (idx > 0 && compare(array[idx], array[idx - 1])) {
            swap(array[idx], array[idx - 1]);
            idx -= 2;
        }
    }
}

int main() {
    unsigned maxn, n;
    string line, num;

    cin >> maxn;
    //cin.get();
    //getline(cin, line);

    string v[n];
    int i = 0;

    //istringstream is(line);
    while(cin >> num) {
        v[i] = num;
        ++i;
    }
    n = i;


    for (i = 0; i < n; ++i) {
        if (v[i].length() > mlen) mlen = v[i].length();
    }
    mlen *= 2;

    gnomeSort(v, n);

    ostringstream oss("");
    for (i = 0; i < n; ++i) {
        oss << v[i];
    }
    cout << oss.str() << endl;
}
