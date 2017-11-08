#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "Bulgarian");
    srand(time(NULL));
    cout << "случайно число: " << rand() % 100 << endl;
}
