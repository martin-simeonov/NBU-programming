#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "EqualPointException.h"
#include <iostream>
#include <fstream>
using namespace std;

Element* e;

void printObjects() {
	cout << "1 – Точка" << endl
		<< "2 – Вектор" << endl
		<< "3 – Линия" << endl
		<< "4 – Отсечка" << endl
		<< "5 – Триъгълник" << endl
		<< "6 - Тетраедър" << endl;
}

Element* createObject(int type) {
	switch (type) {
	case 1: return new Point();
	case 2: return new Vector();
	case 3: return new Line();
	case 4: return new Segment();
	case 5: return new Triangle();
	case 6: return new Tetrahedron();
	default: std::cout << "грешен избор" << std::endl;
	}
	return NULL;
}

void driver(istream& in) {
	bool prompt = false;
	if (&in == &std::cin) prompt = true;

	int choice;
	char yesNo = 'n';	

	while (in) {
		do {
			if (prompt) printObjects();
			in >> choice;
			e = createObject(choice);
		} while (e == NULL);

		try {
			in >> *e;
		}
		catch (EqualPointException epe) {
			cerr << epe.what() << endl;
			continue;
		}

		do {
			if (prompt) e->printMethods();
			in >> choice;

			try {
				e->executeMethod(choice, in, cout);
			}
			catch (VectorLengthException& vle) {
				cerr << vle.what() << endl;
			}
			catch (EqualPointException epe) {
				cerr << epe.what() << endl;
			}
			catch (exception e) {
				cerr << e.what() << endl;
			}

			if (prompt) {
				cout << "Желаете ли да изберете нова операция (y/n)?";
				in >> yesNo;
			} else {
				in.ignore();
			}
		} while (yesNo == 'y' && prompt);

		if (prompt) {
			cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
			in >> yesNo;
			if (yesNo == 'n') break;
		}

		delete e;
	}
}

int main(int argc, char* argv[]) {
	locale::global(locale("Bulgarian"));

	if (argc == 1) {
		driver(cin);
	}
	else {
		ifstream in(argv[1]);
		if (!in) {
			cerr << "Could not open file" << endl;
			return 3;
		}
		driver(in);
		in.close();
	}
}