#include "../includes/ScalarConverter.hpp"
#include <limits.h>
#include <cstdlib>

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

bool	isSpecial(const std::string &str)
{
	std::string specials[6] = {
		"nan",
		"nanf",
		"+inf",
		"-inf",
		"+inff",
		"-inff"
	};

	for (int i = 0; i < 6; i++)
	{
		if (str == specials[i])
			return (true);
	}
	return (false);
}

bool isChar(const std::string &str)
{
	if (str.length() != 1 || !isalpha(str[0]))
		return (false);
	return (true);
}

bool isInt(const std::string &str)
{
	int i = (str[0] == '-');
	int	len = str.length();

	while (i < len)
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isDouble(const std::string &str)
{
	if (str.find('.') != str.rfind('.'))
		return (false);
	
	int i = (str[0] == '-');
	int	len = str.length();
	while (i < len)
	{
		if (!(isdigit(str[i]) || str[i] == '.'))
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(const std::string &str)
{
	if (str[str.length() - 1] != 'f')
		return (false);
	
	std::string tmp = str;
	tmp.erase(tmp.length() - 1);
	if (!isDouble(tmp))
		return (false);
	return (true);
}

scalarType getType(const std::string &str)
{
	if (isSpecial(str))
		return (SPECIAL);
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INT);
	if (isDouble(str))
		return (DOUBLE);
	if (isFloat(str))
		return (FLOAT);
	return (INVALID);
}

void printOutput(char c, int i, float f, double d)
{
	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << ".0f" << std::endl;
	std::cout << "Double: " << d << ".0" << std::endl;
}

void printCustomOutput(std::string c, std::string i, std::string f, std::string d)
{
	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void printSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
		printCustomOutput("Impossible", "Impossible", "nanf", "nan");
	if (str == "+inf" || str == "+inff")
		printCustomOutput("Impossible", "Impossible", "inff", "inf");
	if (str == "-inf" || str == "-inff")
		printCustomOutput("Impossible", "Impossible", "-inff", "-inf");
}

void printChar(const std::string &str)
{
	printOutput(
		static_cast<char>(str[0]),
		static_cast<int>(str[0]),
		static_cast<float>(str[0]),
		static_cast<double>(str[0])
	);
}

void printInt(const std::string &str)
{
	long i = atol(str.c_str());
	if (i < INT_MIN || i > INT_MAX)
		printCustomOutput("Impossible", "Impossible", ".0f", ".0");

	if (isprint(int(i)))
		printOutput(static_cast<char>(i), static_cast<int>(i), static_cast<float>(i), static_cast<double>(i));
	else
	{
		std::cout << "Char: " << "Non displayable" << std::endl;
		std::cout << "Int: " << static_cast<int>(i) << std::endl;
		std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
	}
}

void printFloat(const std::string &str)
{
	float f = atof(str.c_str());
	std::string decimal;
	
	if (isprint(int(f)))
		std::cout << "Char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "Char: " << "Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(f) << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void printDouble(const std::string &str)
{
	double d = atof(str.c_str());
	
	if (isprint(int(d)))
		std::cout << "Char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "Char: " << "Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(d) << std::endl;
	std::cout << "Float: " << static_cast<float>(d) << std::endl;
	std::cout << "Double: " << d << std::endl;
}

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

	//std::cout << type << std::endl;
}
