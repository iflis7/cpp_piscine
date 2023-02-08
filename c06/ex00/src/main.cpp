#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Scalar.hpp"

TEST_CASE("Scalar Test Char Arg")
{
	Scalar c1("a"), c2("b"), c3(".");

	CHECK(c1.getType() == "Char");
	CHECK(c1.getChar() == 'a');
	CHECK(c1.getInt() == 97);
	CHECK(c1.getFloat() == doctest::Approx(97.0f));
	CHECK(c1.getDouble() == 97.00);

	CHECK(c2.getType() == "Char");
	CHECK(c2.getChar() == 'b');
	CHECK(c2.getInt() == 98);
	CHECK(c2.getFloat() == doctest::Approx(98.0f));
	CHECK(c2.getDouble() == 98.00);

	CHECK(c3.getType() == "Char");
	CHECK(c3.getChar() == '.');
	CHECK(c3.getInt() == 46);
	CHECK(c3.getFloat() == 46.0f);
	CHECK(c3.getDouble() == 46.0);
}

TEST_CASE("Scalar Test Int Arg")
{
	Scalar i1("1"), i2("97"), i3("-420");

	CHECK(i1.getType() == "Int");
	CHECK(i1.getChar() == 0);
	CHECK(i1.getInt() == 1);
	CHECK(i1.getFloat() == doctest::Approx(1.0f));
	CHECK(i1.getDouble() == 1.00);

	CHECK(i2.getType() == "Int");
	CHECK(i2.getChar() == 'a');
	CHECK(i2.getInt() == 97);
	CHECK(i2.getFloat() == doctest::Approx(97.0f));
	CHECK(i2.getDouble() == 97.0);

	CHECK(i3.getType() == "Int");
	CHECK(i3.getChar() == 0);
	CHECK(i3.getInt() == -420);
	CHECK(i3.getFloat() == -420.0f);
	CHECK(i3.getDouble() == -420.0);
}

TEST_CASE("Scalar Test Float Arg")
{
	Scalar i1("1.0f"), i2("10.0f"), i3("-420.0f");

	CHECK(i1.getType() == "Float");
	CHECK(i1.getChar() == 0);
	CHECK(i1.getInt() == 1);
	CHECK(i1.getFloat() == doctest::Approx(1.0f));
	CHECK(i1.getDouble() == 1.0);

	CHECK(i2.getType() == "Float");
	CHECK(i2.getChar() == 0);
	CHECK(i2.getInt() == 10);
	CHECK(i2.getFloat() == doctest::Approx(10.0f));
	CHECK(i2.getDouble() == 10.0);

	CHECK(i3.getType() == "Float");
	CHECK(i3.getChar() == 0);
	CHECK(i3.getInt() == -420);
	CHECK(i3.getFloat() == -420.0f);
	CHECK(i3.getDouble() == -420.0);
}

TEST_CASE("Scalar Test Double Arg")
{
	Scalar i1("1.0"), i2("10.0"), i3("-420.0");

	CHECK(i1.getType() == "Double");
	CHECK(i1.getChar() == 0);
	CHECK(i1.getInt() == 1);
	CHECK(i1.getFloat() == doctest::Approx(1.0f));
	CHECK(i1.getDouble() == 1.0);

	CHECK(i2.getType() == "Double");
	CHECK(i2.getChar() == 0);
	CHECK(i2.getInt() == 10);
	CHECK(i2.getFloat() == doctest::Approx(10.0f));
	CHECK(i2.getDouble() == 10.0);

	CHECK(i3.getType() == "Double");
	CHECK(i3.getChar() == 0);
	CHECK(i3.getInt() == -420);
	CHECK(i3.getFloat() == -420.0f);
	CHECK(i3.getDouble() == -420.0);
}

int printableTest(char **argv)
{
	try
	{
		Scalar scalar(argv[1]);
		std::cout << scalar;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

int main(int argc, char **argv)
{
	// Including
	doctest::Context ctx;
	ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
	ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
	ctx.setOption("no-breaks", true); // override - don't break in the debugger
	int res = ctx.run();			  // run test cases unless with --no-run
	if (ctx.shouldExit())			  // query flags (and --exit) rely on this
		return res;					  // propagate the result of the tests
	std::cout << std::endl
			  << std::endl;
	if (argc == 2)
	{
		printableTest(argv);
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;

	return res; // + your_program_res
}
