#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Whatever.hpp"

// TEST_CASE("Scalar Test Int Args")
// {
//     int x = 7;
//     int y = 2;

//     ::swap(x, y); // Swap
//     CHECK(x == 2);
//     CHECK(y == 7);

//     ::swap(x, y); // Swap
//     CHECK(x == 7);
//     CHECK(y == 2);

//     /* Max and Min values */
//     CHECK(max(x, y) == 7);
//     CHECK(min(x, y) == 2);
// }

// TEST_CASE("Scalar Test Float Args")
// {
//     int x = 42.0f;
//     int y = 3.0f;

//     ::swap(x, y); // Swap
//     CHECK(x == 3.0f);
//     CHECK(y == 42.0f);

//     ::swap(x, y); // Swap
//     CHECK(x == 42.0f);
//     CHECK(y == 3.0f);

//     /* Max and Min values */
//     CHECK(max(x, y) == 42.0f);
//     CHECK(min(x, y) == 3.0f);
// }

// TEST_CASE("Scalar Test Double Args")
// {
//     int x = 70.0;
//     int y = 41.0;

//     ::swap(x, y); // Swap
//     CHECK(x == 41.0);
//     CHECK(y == 70.0);

//     ::swap(x, y); // Swap
//     CHECK(x == 70.0);
//     CHECK(y == 41.0);

//     /* Max and Min values */
//     CHECK(max(x, y) == 70.0);
//     CHECK(min(x, y) == 41.0);
// }

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
    std::cout << std::endl;
    std::string a = "First";
    std::string b = "Second";
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
}

int test()
{
    std::cout << std::setw(30) << " ============ Test 1 ============ " << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl
              << std::endl;
    return 0;
}

int test1()
{
    std::cout << std::setw(30) << " ============ Test 2 ============ " << std::endl;

    int x = 42.0f;
    int y = 3.0f;

    ::ft_putvar(x, y); // Check before the swap
    ::swap(x, y);
    ::ft_putvar(x, y); // Check after the swap
    std::cout << "Min = " << ::min(x, y) << std::endl;
    std::cout << "Max = " << ::max(x, y) << std::endl;
    return (0);
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
    std::cout << std::endl;
    test();
    test1();

    return res; // + your_program_res
}
