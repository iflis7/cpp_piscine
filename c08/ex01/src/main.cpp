#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Iter.hpp"

TEST_CASE("Test Int Array")
{
    std::cout << std::setw(30) << " ============ Test Case 1 ============ " << std::endl;
    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int copyArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int value = 7;
    for (int i = 0; i < 13; i++)
    {
        std::cout << intArr[i] << " ";
        CHECK(intArr[i] == copyArr[i] + 7); // check that every value equals the old + 7
    }
    std::cout << std::endl;
}

int test()
{
    std::cout << std::setw(30) << " ============ Test ============ " << std::endl;
    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);
    return 0;
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
