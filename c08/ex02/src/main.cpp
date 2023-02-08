#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/MutantStack.hpp"

int stackTest()
{

    std::cout << std::setw(30) << " ============ Test 1 ============ " << std::endl;
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

int listTest()
{
    std::cout << std::setw(30) << " ============ List Test ============ " << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}

TEST_CASE("Array INT")
{
    // const int count = 5;

    // Array<int> a(count);
    // for (unsigned int i = 0; i < a.getSize(); i++)
    //     a[i] = i;
    // CHECK(a.getSize() == 5);
    // CHECK(a[0] == 0);
    // CHECK(a[2] == 2);
    // CHECK(a[4] == 4);

    // for (unsigned int i = 0; i < a.getSize(); i++)
    //     a[i] = a[i] * 2;
    // CHECK(a[0] == 0);
    // CHECK(a[2] == 4);
    // CHECK(a[4] == 8);
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
    listTest();
    // stackTest();

    return res; // + your_program_res
}
