#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/EasyFind.hpp"

TEST_CASE("Test Vector")
{
    int count = 10;
    std::vector<int> v;
    for (int i = 0; i < count; i++)
        v.push_back(i);

    try
    {
        for (int i = 0; i < count; i++)
        {
            std::vector<int>::iterator it = easyfind(v, i);
            CHECK(*it == i);
            // CHECK(*it == 11); // Should fail because 11 is not in the vector
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST_CASE("Test Vector")
{
    int count = 10;
    std::list<int> v;
    for (int i = 0; i < count; i++)
        v.push_back(i);

    try
    {
        for (int i = 0; i < count; i++)
        {
            std::list<int>::iterator it = easyfind(v, i);
            CHECK(*it == i);
            // CHECK(*it == 11); // Should fail because 11 is not in the list
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

/**
 * @brief Testing a vector
 *
 * @return int the status
 */
int testVect()
{
    std::cout << std::setw(30) << " ============ Test Value not found ============ " << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "It:: " << *it << std::endl;

        it = easyfind(v, 4);
        std::cout << "It:: " << *it << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

/**
 * @brief Testing a list
 *
 * @return int the status
 */
int testList()
{
    std::cout << std::setw(30) << " ============ Test Value not found ============ " << std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(l, 1);
        std::cout << "It:: " << *it << std::endl;

        it = easyfind(l, 4);
        std::cout << "It:: " << *it << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

int main(int argc, char **argv)
{
    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if (ctx.shouldExit())             // query flags (and --exit) rely on this
        return res;                   // propagate the result of the tests
    std::cout << std::endl;
    testVect();
    testList();

    return res; // + your_program_res
}
