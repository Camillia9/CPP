#include "ScalarConverter.hpp"

int main() {

	std::cout << "\n~~~ Conversion depuis int ~~~\n" << std::endl;

	ScalarConverter::convert("9999999999999");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("127");
	std::cout << std::endl;
	ScalarConverter::convert("-5");
	std::cout << std::endl;
	ScalarConverter::convert("1000");
	std::cout << std::endl;

	std::cout << "\n~~~ Conversion depuis char ~~~\n"<< std::endl;

	ScalarConverter::convert("c");
	std::cout << std::endl;
	ScalarConverter::convert("'c'");
	std::cout << std::endl;
	ScalarConverter::convert("A");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("@");

	std::cout << "\n~~~ Conversion depuis float ~~~\n"<< std::endl;


	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.5f");
	std::cout << std::endl;
	ScalarConverter::convert("-4.2f");
	std::cout << std::endl;
	ScalarConverter::convert("0.0f");

	std::cout << "\n~~~ Conversion depuis double ~~~\n" << std::endl;

	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("42.5");
	std::cout << std::endl;
	ScalarConverter::convert("-4.2");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");

	std::cout << "\n~~~ Conversion depuis pseudo-littéraux ~~~\n" << std::endl;

	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nAnf");
	std::cout << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;
	ScalarConverter::convert("iNff");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inFF");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	std::cout << "\n~~~ Tests limites ~~~\n" << std::endl;

	ScalarConverter::convert("fdsfsf");
	std::cout << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;
	ScalarConverter::convert("42.0.0");

}