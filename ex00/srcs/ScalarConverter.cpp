#include "../includes/convert.h"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
	scalarType type = getType(str);

	switch (type) 
	{
		case INVALID:
			std::cout << "Invalid input.\n";
			break ;
		case SPECIAL:
			printSpecial(str);
			break ;
		case CHAR:
			printChar(str);
			break ;
		case INT:
			printInt(str);
			break ;
		case FLOAT:
			printFloat(str);
			break ;
		case DOUBLE:
			printDouble(str);
			break ;
	}
}
