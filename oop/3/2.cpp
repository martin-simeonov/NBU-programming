/*
Дефинирайте клас BigInteger, който съхранява Дефинирайте конструктор BigInteger(string),
който чете последователност от цифри от string. Предефинирайте операторите +, -, и*,
за да можете да събирате, изваждате и умножавате такива големи числа.
Предефинирайте оператора <<, за да можете да изпращате BigInteger число в поток.
Например:
BigInteger a("123456789");
BigInteger b("987654321");
cout << a * b;
Изход: 121932631112635269.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

class BigInteger {
    char* _integer;

    char* doArithmetic(char* a, char* b, int (*operation)(int, int)) const;
    char* doSub(char* a, char* b) const;

    static int sum(int a, int b);
    static int sub(int a, int b);

public:
    BigInteger(const char* integer = "");
    BigInteger(const BigInteger& other);
    ~BigInteger();

    char* getInteger() const;
    BigInteger& setInteger(const char* integer);

    BigInteger& operator=(const BigInteger& other);
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
};

BigInteger::BigInteger(const char* integer) {
    _integer = new char[strlen(integer) + 1];
    strcpy(_integer, integer);
}

BigInteger::BigInteger(const BigInteger& other) {
    _integer = new char[strlen(other._integer) + 1];
    strcpy(_integer, other._integer);
}

BigInteger::~BigInteger() {
    delete [] _integer;
}

char* BigInteger::getInteger() const {
    return _integer;
}

BigInteger& BigInteger::setInteger(const char* integer) {
    _integer = new char[strlen(integer) + 1];
    strcpy(_integer, integer);
    return *this;
}

BigInteger& BigInteger::operator=(const BigInteger& other) {
    if (this != &other) {
        delete [] _integer;
        _integer = new char[strlen(other._integer) + 1];
        strcpy(_integer, other._integer);
    }
    return *this;
}

char* BigInteger::doArithmetic(char* lhs, char* rhs, int (*operation)(int, int)) const {
    int aLen = strlen(lhs);
    int bLen = strlen(rhs);

    char *a, *b, *sum;

    int n;
    int carry;

    a = new char[aLen + 1];
    b = new char[bLen + 1];

    strcpy(a, lhs);

    int diff = aLen - bLen;
    for (int i = 0; i < aLen; ++i) {
        if (i < diff)
            b[i] = '0';
        else
            b[i] = rhs[i - diff];
    }

    sum = new char[aLen + 1];
    carry = 0;

    for (int i = aLen - 1; i >= 0; --i) {
        //n = (a[i] - '0') + (b[i] - '0');
        n = operation((a[i] - '0'), (b[i] - '0'));
        n += carry;

        if (n > 9) {
            sum[i] = (char)n % 10 + '0';
            carry = 1;
        } else {
            sum[i] = (char) n + '0';
            carry = 0;
        }
    }
    sum[aLen] = '\0';

    char* result = new char[aLen + 2];
    result[0] = '1';

    if (carry == 1) {
        strcat(result, sum);
    } else {
        strcpy(result, sum);
        result[aLen] = '\0';
    }

    delete [] a;
    delete [] b;
    delete [] sum;

    return result;
}

char* BigInteger::doSub(char* lhs, char* rhs) const {
    int aLen = strlen(lhs);
    int bLen = strlen(rhs);

    char *a, *b, *sum;

    int n;
    int carry;

    a = new char[aLen + 1];
    b = new char[bLen + 1];

    strcpy(a, lhs);

    int diff = aLen - bLen;
    for (int i = 0; i < aLen; ++i) {
        if (i < diff)
            b[i] = '0';
        else
            b[i] = rhs[i - diff];
    }

    sum = new char[aLen + 1];
    carry = 0;

    int n1, n2;
    for (int i = aLen - 1; i >= 0; --i) {
        n1 = a[i] - '0';
        n2 = b[i] - '0';

        if (n1 - n2 < 0) {
            int j = i - 1;
            do {
                a[j] = (char) ((a[j] - '0') - 1) + '0';
                a[j + 1] = (char) ((a[j + 1] - '0') + 1) + '0';

                --j;
            } while (j >= 0 && a[j] == 0);
        }
        n1 = a[i] - '0';
        n2 = b[i] - '0';

        n = n1 - n2;

        //std::cout << n << std::endl;


        sum[i] = (char) n + '0';
    }
    //sum[aLen] = '\0';

    char* result = new char[aLen + 2];
    result[0] = '1';

    //if (carry == 1) {
    //    strcat(result, sum);
    //} else {
        strcpy(result, sum);
        result[aLen] = '\0';
    //}

    delete [] a;
    delete [] b;
    delete [] sum;

    return result;
}

int BigInteger::sum(int a, int b) { return a + b; }

int BigInteger::sub(int a, int b) { return a - b; }

BigInteger BigInteger::operator+(const BigInteger& other) const {
    int aLen = strlen(_integer);
    int bLen = strlen(other._integer);

    if (aLen > bLen) {
        return BigInteger(doArithmetic(_integer, other._integer, BigInteger::sum));
    } else {
        return BigInteger(doArithmetic(other._integer, _integer, BigInteger::sum));
    }
}

BigInteger BigInteger::operator-(const BigInteger& other) const {
    int aLen = strlen(_integer);
    int bLen = strlen(other._integer);

    std::cout << strcmp(_integer, other._integer) << std::endl;

    if (aLen > bLen) {
        return BigInteger(doSub(_integer, other._integer));
    } else {
        return BigInteger(doSub(other._integer, _integer));
    }
}

std::ostream& operator<<(std::ostream& out, const BigInteger& val) {
    out << val.getInteger();
    return out;
}

int main() {
    BigInteger b1("123456789");
    BigInteger b2("987654321");
    BigInteger b3("9876");

    std::cout << b2 - b3 << std::endl;
}
