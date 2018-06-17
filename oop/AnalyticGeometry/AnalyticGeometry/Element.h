#pragma once
#include <iostream>

class Element {
public:
	virtual std::ostream& ins(std::ostream&) const = 0;
	virtual std::istream& out(std::istream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, const Element&);