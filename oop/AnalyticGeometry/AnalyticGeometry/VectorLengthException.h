#pragma once
#include <exception>

class VectorLengthException : public std::exception {
	const char* what() const throw() {
		return "Vector length is 0";
	}
};