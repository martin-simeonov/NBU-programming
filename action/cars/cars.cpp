//https://action.informatika.bg/problems/164

#include <iostream>
using namespace std;

unsigned count = 0;

int main() {
    int n, num;

    cin >> n;
    cin.ignore();
    int spaces[n + 1];
    int i = 0;
    while (cin >> num) {
        spaces[i] = num;
        ++i;
    }

    unsigned swap;
    int flag = 0;
    for (int i = 0; ; i++) {
        if (spaces[i] == 0) {
            for (int k = 0; k <= n; ++k) {
                if (spaces[k] == i) {
                    spaces[i] = spaces[k];
                    spaces[k] = 0;
                    ++count;
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (spaces[j] != j) flag = 1;
        }
        if (flag)
    }

    for (int i = 0; i <= n; ++i) cout << spaces[i];
    cout << endl;
    cout << count * 10 << endl;
}
