#pragma once
#include <iostream>

class Element {
public:
	virtual std::ostream& ins(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Element&);