#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include <iostream>
using namespace std;

Element* e;

void printObjects() {
	cout << "1 � �����" << endl
		<< "2 � ������" << endl
		<< "3 � �����" << endl
		<< "4 � �������" << endl
		<< "5 � ����������" << endl;
}

Element* createObject(int type) {
	switch (type) {
	case 1: return new Point();
	case 2: return new Vector();
	case 3: return new Line();
	case 4: return new Segment();
	case 5: return new Triangle();
	default: std::cout << "������ �����" << std::endl;
	}
	return NULL;
}

int main() {
	locale::global(locale("Bulgarian"));

	int choice;
	char yesNo;
	while (1) {
		do {
			printObjects();
			cin >> choice;
			e = createObject(choice);
		} while (e == NULL);
		
		try {
			cin >> *e;
		} catch (EqualPointException epe) {
			cerr << epe.what() << endl;
			continue;
		}
		
		do {
			e->printMethods();
			cin >> choice;

			try {
				e->executeMethod(choice, cin, cout);
			} catch (VectorLengthException& vle) {
				cerr << vle.what() << endl;
			} catch (EqualPointException epe) {
				cerr << epe.what() << endl;
			} catch (exception e) {
				cerr << e.what() << endl;
			}
			
			cout << "������� �� �� �������� ���� �������� (y/n)?";
			cin >> yesNo;
		} while (yesNo == 'y');

		cout << "������� �� �� �������� ��� ����������� �����(y/n)?";
		cin >> yesNo;
		if (yesNo == 'n') break;
	}
	delete e;
}