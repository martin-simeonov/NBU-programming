#include "Element.h"

std::ostream& operator<<(std::ostream& out, const Element& e) {
	return e.ins(out);
}