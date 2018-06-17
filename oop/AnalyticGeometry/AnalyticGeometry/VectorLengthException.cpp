#include "VectorLengthException.h"

const char * VectorLengthException::what() const throw() {
	return "Exception vector length is 0";
}
