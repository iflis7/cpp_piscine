#include "../include/Scalar.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Scalar scalar(argv[1]);
			std::cout << std::endl;
			// std::cout << scalar;
			std::cout << "----------- :Scalar: -----------" << std::endl;
			std::cout << "Char: " << scalar.getChar() << std::endl;
			std::cout << "int: " << scalar.getInt() << std::endl;
			std::cout << "float: " << scalar.getFloat() << ".0f" << std::endl;
			std::cout << "double: " << scalar.getDouble() << ".0" << std::endl;
			std::cout << scalar.getType() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;
}
