#include "../includes/ScalarConverter.hpp"

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
	std::string specials[5] = {
		"nan",
		"inf",
		"-inf",
		"inff",
		"-inff"
	};

	for (int i = 0; i < 5; i++)
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

void ScalarConverter::convert(const std::string &str)
{
	scalarType type = getType(str);
	std::cout << type << std::endl;
}
