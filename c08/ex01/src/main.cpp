#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Span.hpp"

TEST_CASE("Test Int Span")
{
    std::cout << std::setw(30) << " ============ Test Case 1 ============ " << std::endl;
    unsigned int count = 100000;

    Span s(count);
    for (int i = 0; i < (int)count; i++)
        s.addNumber(i);

    try
    {
        CHECK(s.shortestSpan() == 1);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {

        CHECK(s.longestSpan() == 99999);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

TEST_CASE("Test Empty ")
{
    Span s(0);
    int thrown = false;
    try
    {
        std::cout << "Span:: " << &s << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        thrown = true;
    }
    CHECK(thrown == false);

    try
    {
        s.shortestSpan();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
        thrown = true;
    }
    CHECK(thrown == false);

}

int test()
{
    std::cout << std::setw(30) << " ============ Test ============ " << std::endl;
    int shortest;
    int longest;

    Span s(5);
    s.addNumber(5);
    s.addNumber(3);
    s.addNumber(17);
    s.addNumber(9);
    s.addNumber(11);
    try
    {
        shortest = s.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        longest = s.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
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
    (void)argc;
    (void)argv;
    test();

    return res; // + your_program_res
}
