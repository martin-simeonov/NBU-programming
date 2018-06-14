#include "VectorLengthException.h"

const char * VectorLengthException::what() const throw() {
	return "Vector length is 0";
}
