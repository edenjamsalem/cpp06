#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Please input a single c++ scalar value.\n";
        return (1);
    }
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;
    ScalarConverter::convert("p");
    std::cout << std::endl;
    ScalarConverter::convert("z");
    std::cout << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    ScalarConverter::convert("-0");
    std::cout << std::endl;
    ScalarConverter::convert("123");
    std::cout << std::endl;
    ScalarConverter::convert("-123");
    std::cout << std::endl;
    
    std::cout << "(double)\n" << std::endl;
    ScalarConverter::convert("123.123");
    std::cout << std::endl;
    std::cout << "(double)\n" << std::endl;
    ScalarConverter::convert("-123.123");
    std::cout << std::endl;
    std::cout << "(float)\n" << std::endl;
    ScalarConverter::convert("123.123f");
    std::cout << std::endl;
    std::cout << "(float)\n" << std::endl;
    ScalarConverter::convert("-123.123f");
    std::cout << std::endl;


    ScalarConverter::convert("0ddwq0");
    std::cout << std::endl;
    ScalarConverter::convert("123.123.123");
    std::cout << std::endl;
    ScalarConverter::convert("s123");
    std::cout << std::endl;
    ScalarConverter::convert("s123.0");
    std::cout << std::endl;
    ScalarConverter::convert("&");
    std::cout << std::endl;
    ScalarConverter::convert("aa");
    std::cout << std::endl;
    ScalarConverter::convert(argv[1]);
}