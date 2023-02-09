#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/MutantStack.hpp"
#include "../include/MutantStack.hpp"

int listTest()
{
    std::cout << std::setw(30) << " ============ listTest ============ " << std::endl;
    std::list<int> list;
    list.push_front(5);
    list.push_front(17);
    std::cout << list.front() << std::endl;
    list.front();
    std::cout << list.size() << std::endl;
    list.push_front(3);
    list.push_front(5);
    list.push_front(737);
    list.push_front(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "*It:: " << *it << std::endl;
        ++it;
    }
    return 0;
}

int mainTest()
{
    std::cout << std::setw(30) << " ============ mainTest ============ " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top():: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack.size():: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); // Creating the begin iterator
    MutantStack<int>::iterator ite = mstack.end();  // Creating the end iterator
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "*It:: " << *it << std::endl;
        ++it;
    }
    return 0;
}

TEST_CASE("INT STACK Tests")
{
    MutantStack<int> a;
    // PUSH
    a.push(5);
    CHECK(a.top() == 5);

    a.push(17);
    CHECK(a.top() == 17);

    a.push(1000);
    CHECK(a.top() == 1000);

    // POP
    a.pop();
    CHECK(a.top() == 17);

    a.pop();
    CHECK(a.top() == 5);
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
    (void)argc;
    (void)argv;
    mainTest();
    std::cout << std::endl;
    listTest();

    return res; // + your_program_res
}
