//f86388_10b.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;


class classcomp {
public:
    bool operator() (const string& s1, const string& s2) const {
        set<char> set1, set2;
        for (int i = 0; i < s1.length(); ++i) set1.insert(s1[i]);
        for (int i = 0; i < s2.length(); ++i) set2.insert(s2[i]);
        //for (set<char>::iterator it=set1.begin(); it != set1.end(); ++it) cout << (*it) << endl;
        return set1 < set2;
    }
};

int main() {
    string str, line;
    set<string, classcomp> s;

    while (getline(cin, line)) {
        istringstream iss(line);
        while (iss >> str) {
            s.insert(str);
        }
    //    for (set<string, classcomp>::iterator it=s.begin(); it != s.end(); ++it)
      //      cout << (*it) << endl;

        cout << s.size() << endl;
        s.clear();
    }
}
