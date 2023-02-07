#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Whatever.hpp"

// int main(void)
// {
//     {
//         std::cout << std::setw(30) << " ============ ============ " << std::endl;
//         std::cout << std::setw(30) << " ========= Test Int ========= " << std::endl;
//         int x = 42.0f;
//         int y = 3.0f;

//         ::ft_putvar(x, y); // Check before the swap
//         ::swap(x, y);
//         ::ft_putvar(x, y); // Check after the swap
//         std::cout << "Min = " << ::min(x, y) << std::endl;
//         std::cout << "Max = " << ::max(x, y) << std::endl;
//     }
//     return (0);
// }

TEST_CASE("Scalar Test Int Args")
{
    int x = 7;
    int y = 2;

    ::swap(x, y); // Swap
    CHECK(x == 2);
    CHECK(y == 7);

    ::swap(x, y); // Swap
    CHECK(x == 7);
    CHECK(y == 2);

    /* Max and Min values */
    CHECK(max(x, y) == 7);
    CHECK(min(x, y) == 2);
}

TEST_CASE("Scalar Test Float Args")
{
    int x = 42.0f;
    int y = 3.0f;

    ::swap(x, y); // Swap
    CHECK(x == 3.0f);
    CHECK(y == 42.0f);

    ::swap(x, y); // Swap
    CHECK(x == 42.0f);
    CHECK(y == 3.0f);

    /* Max and Min values */
    CHECK(max(x, y) == 42.0f);
    CHECK(min(x, y) == 3.0f);
}

TEST_CASE("Scalar Test Double Args")
{
    int x = 70.0;
    int y = 41.0;

    ::swap(x, y); // Swap
    CHECK(x == 41.0);
    CHECK(y == 70.0);

    ::swap(x, y); // Swap
    CHECK(x == 70.0);
    CHECK(y == 41.0);

    /* Max and Min values */
    CHECK(max(x, y) == 70.0);
    CHECK(min(x, y) == 41.0);
}
TEST_CASE("Scalar Test String Args")
{
    std::string x = "First";
    std::string y = "Second";

    ::swap(x, y); // Swap
    CHECK(y == "First");
    CHECK(x == "Second");

    ::swap(x, y); // Swap
    CHECK(x == "First");
    CHECK(y == "Second");

    /* Max and Min values */
    // CHECK(max(x.c_str(), y.c_str()) == "Second");
    // CHECK(min(x.c_str(), y.c_str()) == "first");
    // // std::string s{"he"}, t{"ho"};
    // auto c = max(s, t); 
}

int main(int argc, char **argv)
{
    // Including
    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if (ctx.shouldExit())             // query flags (and --exit) rely on this
        return res;                   // propagate the result of the tests
    std::cout << std::endl
              << std::endl;
    // if (argc == 2)
    // {
    // 	try
    // 	{
    // 		Scalar scalar(argv[1]);
    // 		std::cout << scalar;
    // 		std::cout << std::endl;
    // 	}
    // 	catch (const std::exception &e)
    // 	{
    // 		std::cerr << e.what() << std::endl;
    // 	}
    // }
    // else
    // 	std::cerr << "Usage: ./convert <value>" << std::endl;
    return res; // + your_program_res
}
