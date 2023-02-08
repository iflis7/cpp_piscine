#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/EasyFind.hpp"

TEST_CASE("Scalar Test Double Args")
{
    int x = 70.0;
    int y = 41.0;

    CHECK(x == 41.0);
    CHECK(y == 70.0);
}

int test1()
{
    std::cout << std::setw(30) << " ============ Test 2 ============ " << std::endl;
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
    test1();

    return res; // + your_program_res
}
