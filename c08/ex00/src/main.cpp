#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/EasyFind.hpp"

TEST_CASE("Test Int Args")
{
    int count = 10;
    std::vector<int> v;
    // for(int i = 0, j = 0; i < count; i++, j += 2)
    // v.push_back(j);
    for (int i = 0; i < count; i++)
        v.push_back(i);

    try
    {
        for (int i = 0; i < count; i++)
        {
            std::vector<int>::iterator it = easyfind(v, i);
            CHECK(*it == i);
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST_CASE("Test Int Args")
{
    int count = 10;
    std::vector<int> v;
    // for(int i = 0, j = 0; i < count; i++, j += 2)
    // v.push_back(j);
    for (int i = 0; i < count; i++)
        v.push_back(i);

    try
    {
        for (int i = 0; i < count; i++)
        {
            std::vector<int>::iterator it = easyfind(v, i);
            CHECK(*it == i);
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int test()
{
    std::cout << std::setw(30) << " ============ Test Value not found ============ " << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << *it << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
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
    test();
    // test1();

    return res; // + your_program_res
}
