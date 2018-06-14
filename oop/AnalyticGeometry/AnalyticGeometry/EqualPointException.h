#pragma once
#include <exception>
#include <string>
#include "Point.h"

class EqualPointException : public std::exception {
	std::string message;
public:
	EqualPointException(std::string, std::string, const Point&);
	const char* what() const throw();
};