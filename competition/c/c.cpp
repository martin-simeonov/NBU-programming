#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

int toDecimal(int base, string s) {
    int m = 0;
    for (int i = 0; i < s.length(); i++) {
        m *= base;
        if (s[i] > 64)
            m += s[i] - '7';
        else
            m += s[i] - '0';
    }
    return m;
}

int main() {
    Node n1(1);
    Node n2(2);

    cout << toDecimal(10, "8") << endl;

    n1.addLink(Link(&n2, 22));
    n1.addLink(Link(&n2, 23));
    //n1.printLinks();
}
