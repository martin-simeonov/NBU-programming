//https://action.informatika.bg/problems/215

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    unsigned n, l;
    string word;
    cin >> n >> l;
    cin.ignore();
    cin >> word;

    int i = 0;

    string sub = word.substr(i, l);
    sort(sub.begin(), sub.end());
    string min = sub + word.substr(l, n - l);
    string temp;

    for (i = 0; i <= (n - l); ++i) {
        sub = word.substr(i, l);
        sort(sub.begin(), sub.end());
        temp = word.substr(0, i) + sub + word.substr(i + l, n - l);
        if (temp < min)
            min = temp;
    }
    cout << min << endl;
}
