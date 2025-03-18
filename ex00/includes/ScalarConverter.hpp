#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>

enum scalarType
{
	INVALID,
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

// typedef enum special
// {
// 	NAN,
// 	INF,
// 	INFF,
// 	NEG_INF,
// 	NEG_INFF,
// };

class ScalarConverter
{
	public:
		static void convert(const std::string &str);
		
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

};

#endif
