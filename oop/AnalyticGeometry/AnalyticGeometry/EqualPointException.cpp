#include "EqualPointException.h"
#include <cstring>

EqualPointException::EqualPointException(const Point& p) 
	: message(new char[50])
{
	sprintf_s(message, 50, "P(%.2f, %.2f, %.2f) is equal", p.getX(), p.getY(), p.getZ());
}

EqualPointException::EqualPointException(const EqualPointException& other)
	: message(new char[strlen(other.message) + 1])
{
	strcpy_s(message, strlen(other.message) + 1, other.message);
}

EqualPointException::~EqualPointException() {
	delete[] message;
}

EqualPointException& EqualPointException::operator=(const EqualPointException& other) {
	if (this != &other) {
		delete[] message;
		message = new char[strlen(other.message) + 1];
		strcpy_s(message, strlen(other.message) + 1, other.message);
	}
	return *this;
}

const char * EqualPointException::what() const throw() {
	return message;
}
