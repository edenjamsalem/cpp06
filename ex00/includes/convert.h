#include "../includes/ScalarConverter.hpp"
#include <limits.h>
#include <cstdlib>

#ifndef CONVERT_H
#define CONVERT_H

void printCustomOutput(std::string c, std::string i, std::string f, std::string d);

void printSpecial(const std::string &str);

void printChar(const std::string &str);

void printInt(const std::string &str);

void printFloat(const std::string &str);

void printDouble(const std::string &str);

bool isSpecial(const std::string &str);

bool isChar(const std::string &str);

bool isInt(const std::string &str);

bool isDouble(const std::string &str);

bool isFloat(const std::string &str);

scalarType getType(const std::string &str);

#endif