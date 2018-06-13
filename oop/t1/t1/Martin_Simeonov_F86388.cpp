#include <iostream>
using namespace std;

// Task 1
class Medicine {
	double _salePrice;
	int _expirationTime;

	friend ostream& operator<<(ostream&, const Medicine&);
public:
	Medicine();
	Medicine(double, int);

	bool operator<(unsigned) const;
	Medicine& lowerPriceIfExpire(double);

	double getPrice() const;
};

Medicine::Medicine()
	:_salePrice(0), _expirationTime(0)
{}

Medicine::Medicine(double salePrice, int expirationTime)
	:_salePrice(salePrice), _expirationTime(expirationTime)
{}

bool Medicine::operator<(unsigned time) const {
	if (_expirationTime < time) {
		return true;
	}
	else {
		return false;
	}
}

Medicine& Medicine::lowerPriceIfExpire(double percent) {
	if (*this < 3) {
		_salePrice -= (_salePrice / 100) * percent;
	}
	return *this;
}

double Medicine::getPrice() const {
	return _salePrice;
}

ostream& operator<<(ostream& out, const Medicine& medicine) {
	out << "price: " << medicine._salePrice << ", expires in " << medicine._expirationTime << " months";
	return out;
}

// Task 2
class Pharmacy {
	int _medicineCount;
	Medicine* _medicineList;
public:
	Pharmacy();
	Pharmacy(int, Medicine*);
	Pharmacy(const Pharmacy&);
	~Pharmacy();
	Pharmacy& operator=(const Pharmacy&);
	Medicine& operator[](unsigned);
	double operator()() const;

	Pharmacy& deliverMedicine(Medicine&);
};

Pharmacy::Pharmacy()
	:_medicineCount(0), _medicineList(NULL)
{}

Pharmacy::Pharmacy(int medicineCount, Medicine* medicineList)
	:_medicineCount(medicineCount), _medicineList(new Medicine[medicineCount])
{
	for (int i = 0; i < medicineCount; ++i) {
		_medicineList[i] = medicineList[i];
	}
}

Pharmacy::Pharmacy(const Pharmacy& other)
	:_medicineCount(other._medicineCount), _medicineList(new Medicine[other._medicineCount])
{
	for (int i = 0; i < other._medicineCount; ++i) {
		_medicineList[i] = other._medicineList[i];
	}
}

Pharmacy::~Pharmacy() {
	delete[] _medicineList;
}

Pharmacy& Pharmacy::operator=(const Pharmacy& other) {
	if (this != &other) {
		_medicineCount = other._medicineCount;
		if (_medicineList != NULL) delete[] _medicineList;
		_medicineList = new Medicine[other._medicineCount];

		for (int i = 0; i < _medicineCount; ++i) {
			_medicineList[i] = other._medicineList[i];
		}
	}
	return *this;
}

Medicine& Pharmacy::operator[](unsigned index) {
	return _medicineList[index];
}

Pharmacy& Pharmacy::deliverMedicine(Medicine& medicine) {
	Pharmacy temp(*this);

	delete[] _medicineList;
	_medicineList = new Medicine[++_medicineCount];

	for (int i = 0; i < _medicineCount - 1; ++i) {
		_medicineList[i] = temp._medicineList[i];
	}
	_medicineList[_medicineCount - 1] = medicine;
	
	return *this;
}

double Pharmacy::operator()() const {
	double sum = 0.0;
	for (int i = 0; i < _medicineCount; ++i) {
		sum += _medicineList[i].getPrice();
	}
	return sum;
}

// Task 3
class CountDouble {
	double _countDouble;
	int _count;
public:
	CountDouble();
	CountDouble(double countDouble);
	~CountDouble();
	CountDouble& operator=(double);
	CountDouble& operator=(const CountDouble&);

	double getValue() const;
	int getCount() const;
};

CountDouble::CountDouble()
	:_countDouble(0.0), _count(0)
{}

CountDouble::CountDouble(double countDouble)
	: _countDouble(countDouble), _count(0)
{}

CountDouble::~CountDouble() {
	cout << "Object destroyed value = " << _countDouble 
		<< ", assignment count = " << _count << endl;
}

CountDouble& CountDouble::operator=(double other) {
	if (_countDouble > other) ++_count;
	_countDouble = other;
	return *this;
}

CountDouble& CountDouble::operator=(const CountDouble& other) {
	if (this != &other) {
		*this = other._countDouble;
	}
	return *this;
}

double CountDouble::getValue() const {
	return _countDouble;
}

int CountDouble::getCount() const {
	return _count;
}

double operator+(double lhs, const CountDouble& rhs) {
	return lhs + rhs.getValue();
}

double operator+(const CountDouble& lhs, double rhs) {
	return lhs.getValue() + rhs;
}

double operator-(double lhs, const CountDouble& rhs) {
	return lhs - rhs.getValue();
}

double operator-(const CountDouble& lhs, double rhs) {
	return lhs.getValue() - rhs;
}

double operator*(double lhs, const CountDouble& rhs) {
	return lhs * rhs.getValue();
}

double operator*(const CountDouble& lhs, double rhs) {
	return lhs.getValue() * rhs;
}

double operator/(double lhs, const CountDouble& rhs) {
	return lhs / rhs.getValue();
}

double operator/(const CountDouble& lhs, double rhs) {
	return lhs.getValue() / rhs;
}

ostream& operator<<(ostream& out, const CountDouble& rhs) {
	out << rhs.getValue();
	return out;
}

int main() {
	// Task 1
	Medicine m(100, 2);
	cout << m << endl;
	m.lowerPriceIfExpire(20);
	cout << m << endl;
	cout << "###########" << endl << endl;

	// Task 2
	Pharmacy p;
	p.deliverMedicine(m);
	cout << p() << endl;

	Pharmacy p2(p);
	Medicine m2(100, 3);
	p2.deliverMedicine(m2);
	cout << p2[1] << endl;
	cout << p2() << endl;

	Pharmacy p3 = p2;
	Medicine m3(50, 3);
	p3.deliverMedicine(m3);
	cout << p3[0] << endl;
	cout << p3() << endl;
	cout << "###########" << endl << endl;

	// Task 3
	CountDouble c1(3);
	CountDouble c2;
	cout << c2.getCount() << endl;
	c2 = 4;
	cout << c2.getCount() << endl;
	c2 = c1;
	cout << c2.getCount() << endl;

	CountDouble c3;
	c3 = c2 + (3 / c1) * CountDouble(12);
	cout << c3 << endl;
}