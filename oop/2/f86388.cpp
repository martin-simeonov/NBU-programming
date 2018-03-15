#include <iostream>
#include <cstdlib>

class FlowersShop {
    unsigned _count;
    double _price;
public:
    FlowersShop();
    FlowersShop(double price);
    FlowersShop(unsigned count, double price);
    void print() const;
    FlowersShop& increaseFlowers(unsigned count = 1);
    FlowersShop& decreaseFlowers(unsigned count = 1);
    FlowersShop& increasePrice(double price = 1);
    FlowersShop& decreasePrice(double price = 1);
    double turnover() const;
    FlowersShop simulatingPriceDecrease() const;
};

FlowersShop::FlowersShop()
: _count(0), _price(0)
{}

FlowersShop::FlowersShop(double price)
: _count(0), _price(price)
{}

FlowersShop::FlowersShop(unsigned count, double price)
: _count(count), _price(price)
{}

void FlowersShop::print() const {
    std::cout << "count: " << _count << ", price: " << _price << std::endl;
}

FlowersShop& FlowersShop::increaseFlowers(unsigned count) {
    _count += count;
    return *this;
}

FlowersShop& FlowersShop::decreaseFlowers(unsigned count) {
    _count -= count;
    return *this;
}

FlowersShop& FlowersShop::increasePrice(double price) {
    _price += price;
    return *this;
}

FlowersShop& FlowersShop::decreasePrice(double price) {
    _price -= price;
    return *this;
}

double FlowersShop::turnover() const {
    return _count * _price;
}

FlowersShop FlowersShop::simulatingPriceDecrease() const {
    FlowersShop f(_count, _price - ((_price / 100) * 20));
    return f;
}

void print(FlowersShop flowersShop) {
    flowersShop.print();
}

void printRef(const FlowersShop &flowersShop) {
    flowersShop.print();
}

int main() {
    FlowersShop f1;
    f1.increaseFlowers().increasePrice(101);
    f1.print();
    f1.increaseFlowers(5).decreasePrice();
    f1.print();
    f1.simulatingPriceDecrease().print();

    FlowersShop f2(4, 5);
    f2.print();
    f2.decreaseFlowers(2).increasePrice();
    f2.print();
    f2.simulatingPriceDecrease().print();

    print(f1);
    printRef(f2);

    srand(time(NULL));

    int index = 0;
    double maxTurnover = 0;

    FlowersShop fArr[10];
    for (int i = 0; i < 10; ++i) {
        fArr[i].increaseFlowers(rand() % 100 + 1).increasePrice(rand() % 10 + 1);
        fArr[i].print();
        if (fArr[i].turnover() > maxTurnover) {
            index = i;
            maxTurnover = fArr[i].turnover();
        }
    }

    std::cout << "max turnover: " << maxTurnover << " shop: " << index << " - ";
    fArr[index].print();
}
