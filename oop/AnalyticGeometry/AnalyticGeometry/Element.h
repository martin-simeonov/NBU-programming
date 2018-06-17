#pragma once
#include <iostream>

class Element {
public:
	virtual ~Element();

	virtual std::ostream& ins(std::ostream&) const = 0;
	virtual std::istream& out(std::istream&) = 0;

	virtual void printMethods() const = 0;
	virtual void executeMethod(int, std::istream&, std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);