#include "../includes/convert.h"

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
	std::cout << "Char: '" << static_cast<char>(str[0]) << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "Float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void printInt(const std::string &str)
{
	long i = atol(str.c_str());
	if (i < INT_MIN || i > INT_MAX)
		printCustomOutput("Impossible", "Impossible", ".0f", ".0");

	if (isprint(int(i)))
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "Char: " << "Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(i) << std::endl;
	std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
}

void printFloat(const std::string &str)
{
	float f = atof(str.c_str());
	
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
	std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}