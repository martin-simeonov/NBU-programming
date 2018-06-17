#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include <iostream>
using namespace std;

int main() {
	locale::global(locale("Bulgarian"));
	
	Triangle t;
	cin >> t;

	Triangle t2(t);
	Triangle t3;
	t3 = t2;
	cout << t2 << endl;
	cout << t3 << endl;
}