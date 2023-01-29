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
			std::cout << scalar;
            // std::cout << scalar.getType() << std::endl;

		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;
}
