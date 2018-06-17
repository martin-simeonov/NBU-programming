#include "Element.h"

std::ostream& operator<<(std::ostream& out, const Element& e) {
	return e.ins(out);
}

std::istream& operator>>(std::istream& in, Element& e) {
	return e.out(in);
}