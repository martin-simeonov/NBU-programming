/*
Дефинирайте клас Money, който съхранява две член-данни цели числа представляващи левове и стотинки.
Да се предефинират аритметичните оператори, операторите за сравнение,
както и входните и изходни оператори за вмъкване и  извличане от поток за работа с обекти от класа.
Необходимо ли е да се предефинират операторите * и /? Какъв вид аргументи те трябва да приемат?
Предефинирайте оператора %, така че ако n  е стойност с плаваща запетая,
то n % m изчислява n процента от парите m.
*/

#include <iostream>
#include <iomanip>

class Money {
    int _lev;
    int _stotinki;
public:
    Money();
    Money(int lev, int stotinki);

    Money& setLev(int lev);
    Money& setStotinki(int stotinki);
    int getLev() const;
    int getStotinki() const;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(float val) const;
    Money operator/(float val) const;
    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    Money& operator*=(float val);
    Money& operator/=(float val);
    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>=(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
};

Money::Money() {
    _lev = 0;
    _stotinki = 0;
}

Money::Money(int lev, int stotinki)
: _lev(lev), _stotinki(stotinki)
{}

Money& Money::setLev(int lev) {
    _lev = lev;
    return *this;
}

Money& Money::setStotinki(int stotinki) {
    _stotinki = stotinki;
    return *this;
}

int Money::getLev() const {
    return _lev;
}

int Money::getStotinki() const {
    return _stotinki;
}

Money Money::operator+(const Money& other) const {
    return Money(_lev, _stotinki) += other;
}

Money Money::operator-(const Money& other) const {
    return Money(_lev, _stotinki) -= other;
}

Money Money::operator*(float val) const {
    return Money(_lev, _stotinki) *= val;
}

Money Money::operator/(float val) const {
    return Money(_lev, _stotinki) /= val;
}

Money& Money::operator+=(const Money& other) {
    _lev += other._lev;
    _stotinki += other._stotinki;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    _lev -= other._lev;
    _stotinki -= other._stotinki;
    return *this;
}

Money& Money::operator*=(float val) {
    float amount = _lev + (_stotinki / 100.0f);
    amount *= val;
    _lev = (int) amount;
    // 0.5 is added to avoid integer truncation
    _stotinki = (amount - (int) amount) * 100 + 0.5;

    return *this;
}

Money& Money::operator/=(float val) {
    float amount = _lev + (_stotinki / 100.0f);
    amount /= val;
    _lev = (int) amount;
    _stotinki = (amount - (int) amount) * 100 + 0.5;
    return *this;
}

Money& Money::operator++() {
    return *this += Money(1, 1);
}

Money Money::operator++(int) {
    Money temp = *this;
    *this += Money(1, 1);
    return temp;
}

Money& Money::operator--() {
    return *this -= Money(1, 1);
}

Money Money::operator--(int) {
    Money temp = *this;
    *this -= Money(1, 1);
    return temp;
}

bool Money::operator>(const Money& other) const {
    if (_lev > other._lev) {
        return true;
    } else if (_lev == other._lev) {
        return _stotinki > other._stotinki;
    } else {
        return false;
    }
}

bool Money::operator<(const Money& other) const {
    if (_lev < other._lev) {
        return true;
    } else if (_lev == other._lev) {
        return _stotinki < other._stotinki;
    } else {
        return false;
    }
}

bool Money::operator>=(const Money& other) const {
    return *this > other || *this == other;
}

bool Money::operator<=(const Money& other) const {
    return *this < other || *this == other;
}

bool Money::operator==(const Money& other) const {
    return _lev == other._lev && _stotinki == other._stotinki;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Money& value) {
    out << value.getLev() << "," << std::setw(2)
        << std::setfill('0') <<  value.getStotinki();
    return out;
}

std::istream& operator>>(std::istream& in, Money& value) {
    int lev, stotinki;
    in >> lev >> stotinki;
    value = Money(lev, stotinki);
    return in;
}

Money operator%(float n, const Money& money) {
    float amount = money.getLev() + (money.getStotinki() / 100.0f);
    amount /= 100.0f;
    amount *= n;
    return Money((int) amount, (amount - (int) amount) * 100 + 0.5);
}

int main() {
    Money m(2, 35);
    Money m2(2, 35);

    std::cout << m << std::endl;
    m*=2;
    std::cout << 10 % m << std::endl;
}
