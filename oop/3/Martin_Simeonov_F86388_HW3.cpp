#include <iostream>
#include <cassert>
#include <cstdlib>

class HotelRoom {
    unsigned* _reservations;
    double* _prices;
    size_t _size;
    size_t _capacity;

    void resize(size_t = 0);
public:
    HotelRoom(unsigned* = 0, double* = 0, size_t = 0, size_t = 2);
    HotelRoom(const HotelRoom&);
    ~HotelRoom();
    HotelRoom& operator=(const HotelRoom&);

    HotelRoom& addReservation(int, double);
    double highestPrice() const;
};

void HotelRoom::resize(size_t capacity) {
    if (capacity == 0) _capacity *= 2;
    else _capacity = capacity;

    HotelRoom temp(*this);
    if (_reservations != NULL) delete [] _reservations;
    if (_prices != NULL) delete [] _prices;

    _reservations = new unsigned[_capacity];
    _prices = new double[_capacity];

    for (size_t i = 0; i < temp._size; ++i) {
        _reservations[i] = temp._reservations[i];
        _prices[i] = temp._prices[i];
    }
}

HotelRoom::HotelRoom(unsigned* reservations, double* prices,
    size_t size, size_t capacity)
: _size(size), _capacity(capacity), _reservations(new unsigned[_capacity]),
    _prices(new double[_capacity]) {
    assert(_reservations != NULL);
    assert(_prices != NULL);
    for (size_t i = 0; i < _size; ++i) {
        _reservations[i] = reservations[i];
        _prices[i] = prices[i];
    }
}

HotelRoom::HotelRoom(const HotelRoom& other) {
    _size = other._size;
    _capacity = other._capacity;
    _reservations = new unsigned[_capacity];
    _prices = new double[_capacity];

    for (size_t i = 0; i < _size; ++i)  {
        _reservations[i] = other._reservations[i];
        _prices[i] = other._prices[i];
    }
}

HotelRoom::~HotelRoom() {
    delete [] _reservations;
    delete [] _prices;
}

HotelRoom& HotelRoom::operator=(const HotelRoom& other) {
    if (this != &other) {
        _size = other._size;
        _capacity = other._capacity;

        if (_reservations != NULL) delete [] _reservations;
        if (_prices != NULL) delete [] _prices;

        _reservations = new unsigned[_capacity];
        _prices = new double[_capacity];

        for (size_t i = 0; i < _size; ++i) {
            _reservations[i] = other._reservations[i];
            _prices[i] = other._prices[i];
        }
    }
    return *this;
}

HotelRoom& HotelRoom::addReservation(int id, double price) {
    if (_size == _capacity) resize();
    _reservations[_size] = id;
    _prices[_size] = price;
    ++_size;

    return *this;
}

double HotelRoom::highestPrice() const {
    double max = 0;
    for (size_t i = 0; i < _size; ++i) {
        if (_prices[i] > max)
            max = _prices[i];
    }
    return max;
}

void print(const HotelRoom& room) {
    std::cout << "highest price: "<< room.highestPrice() << std::endl;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 3; ++i) {
        HotelRoom h;
        for (int j = 0; j < 10; ++j) {
            h.addReservation(rand() % 50 + 1, rand() % 100);
        }
        print(h);
    }
}
