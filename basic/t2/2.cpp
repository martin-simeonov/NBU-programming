#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string first_letters(string str) {
    string word;
    istringstream iss(str);
    ostringstream oss;
    while (iss >> word) {
        word[0] = toupper(word[0]);
        oss << word[0];
    }
    return oss.str();
}

int main() {
    //setlocale(LC_ALL, "Bulgarian");
// /    cout << first_letters("fasd dsds s") << endl;

    cout << first_letters("Национален осигурителен институт") << endl;
}
