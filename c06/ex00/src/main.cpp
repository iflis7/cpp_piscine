#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Scalar.hpp"
#include "../../doctest.h"

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		try
// 		{
// 			Scalar scalar(argv[1]);
// 			std::cout << std::endl;
// 			// std::cout << scalar;
// 			std::cout << "----------- :Scalar: -----------" << std::endl;
// 			std::cout << "Char: " << scalar.getChar() << std::endl;
// 			std::cout << "int: " << scalar.getInt() << std::endl;
// 			std::cout << "float: " << scalar.getFloat() << std::endl;
// 			std::cout << "double: " << scalar.getDouble() << std::endl;
// 			std::cout << scalar.getType() << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	else
// 		std::cerr << "Usage: ./convert <value>" << std::endl;
// }


TEST_CASE("Scalar Test Char arg")
{
	Scalar s1("a"), s2("1"), f("0.02");

	CHECK(s1.getType() == "Char");
	CHECK(s1.getChar() == 'a');
	CHECK(s1.getInt() == 97);


	CHECK(s2.getType() == "Char");
	CHECK(s2.getChar() == '1');
	CHECK(s2.getInt() == 49);

	// CHECK(0.02 == doctest::Approx(0.02));
	CHECK(f.getFloat() == doctest::Approx(0.02));
	// CHECK(f.getType() == "Char");
	// CHECK(f.getChar() == '0');
	// CHECK(f.getInt() == 48);


}

// int main(int argc, char **argv)
// {
// 	doctest::Context context;
// 	context.applyCommandLine(argc, argv);
// 	int result = context.run();
// 	return result;
// }


int main(int argc, char** argv) {
    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if(ctx.shouldExit())              // query flags (and --exit) rely on this
        return res;                   // propagate the result of the tests
    // your code goes here
    return res; // + your_program_res
}

