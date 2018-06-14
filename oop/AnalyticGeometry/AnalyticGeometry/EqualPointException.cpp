#include "EqualPointException.h"
#include <sstream>

EqualPointException::EqualPointException(std::string a, std::string b, const Point& p) {
	std::ostringstream ss;
	ss << "Point " << a << " and " << b << ", " << p << " are equal";
	message = ss.str();
}

const char * EqualPointException::what() const throw() {
	return message.c_str();
}
