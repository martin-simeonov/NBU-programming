#pragma once
#include <exception>
#include "Point.h"

class EqualPointException : public std::exception {
	char* message;
public:
	EqualPointException(const Point&);
	EqualPointException(const EqualPointException&);
	~EqualPointException();
	EqualPointException& operator=(const EqualPointException&);
	const char* what() const throw();
};