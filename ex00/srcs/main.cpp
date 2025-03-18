#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Please input a single c++ scalar value.\n";
        return (1);
    }
    ScalarConverter::convert("inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("a");
    ScalarConverter::convert("p");
    ScalarConverter::convert("z");
    ScalarConverter::convert("0");
    ScalarConverter::convert("-0");
    ScalarConverter::convert("123");
    ScalarConverter::convert("-123");
    ScalarConverter::convert("123.123");
    ScalarConverter::convert("-123.123");
    ScalarConverter::convert("123.123f");
    ScalarConverter::convert("-123.123f");


    ScalarConverter::convert("0ddwq0");
    ScalarConverter::convert("123.123.123");
    ScalarConverter::convert("s123");
    ScalarConverter::convert("s123.0");
    ScalarConverter::convert("&");
    ScalarConverter::convert("aa");
    ScalarConverter::convert(argv[1]);

}