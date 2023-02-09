#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/MutantStack.hpp"
#include "../include/MutantStack.hpp"

int stackTest()
{
    // const int count = 5;

    std::cout << std::setw(30) << " ============ Test 1 ============ " << std::endl;
    MutantStack<int> a;
    // a.printArr();

    // std::cout << std::endl << std::setw(30) << " ============ Test Out Of Range ============ " << std::endl;
    // Array<int> e;

    // try
    // {
    //     std::cout << e[0] << std::endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    return (0);
}

int test1()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top():: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack.size():: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    std::cout << "mstack.begin():: " << *it << std::endl;
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "mstack.end()  :: " << *it << std::endl;
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

TEST_CASE("Array INT")
{
    // for (unsigned int i = 0; i < a.getSize(); i++)
    //     a[i] = a[i] * 2;
    // CHECK(a[0] == 0);
    // CHECK(a[2] == 4);
    // CHECK(a[4] == 8);
}

TEST_CASE("STRING Array Tests")
{
    // const int count = 5;
    // Array<std::string> c(count);
    // c[0] = "Velkacem";
    // c[1] = "Yuva";
    // c[2] = "Vel3id";
    // c[3] = "Qsam";
    // c[4] = "Arezqi";
    // CHECK(c.getSize() == 5);
    // CHECK(c[0] == "Velkacem");
    // CHECK(c[2] == "Vel3id");
    // CHECK(c[4] == "Arezqi");
    // for (unsigned int i = 0; i < c.getSize(); i++)
    //     c[i] = c[i].append(" n at winat").data();
    // CHECK(c[0] == "Velkacem n at winat");
    // CHECK(c[2] == "Vel3id n at winat");
    // CHECK(c[4] == "Arezqi n at winat");
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
    // printableTests();
    test1();

    return res; // + your_program_res
}
