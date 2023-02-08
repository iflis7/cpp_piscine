#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Array.hpp"

int printableTests()
{
    const int count = 5;

    std::cout << std::setw(30) << " ============ Test 1 ============ " << std::endl;
    Array<int> a(count);
    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = rand() % 100 + 1;
    a.printArr();

    std::cout << std::endl << std::setw(30) << " ============ Test Out Of Range ============ " << std::endl;
    Array<int> e;

    try
    {
        std::cout << e[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

TEST_CASE("Array INT")
{
    const int count = 5;

    Array<int> a(count);
    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = i;
    CHECK(a.getSize() == 5);
    CHECK(a[0] == 0);
    CHECK(a[2] == 2);
    CHECK(a[4] == 4);

    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = a[i] * 2;
    CHECK(a[0] == 0);
    CHECK(a[2] == 4);
    CHECK(a[4] == 8);
}

TEST_CASE("STRING Array Tests")
{
    const int count = 5;
    Array<std::string> c(count);
    c[0] = "Velkacem";
    c[1] = "Yuva";
    c[2] = "Vel3id";
    c[3] = "Qsam";
    c[4] = "Arezqi";
    CHECK(c.getSize() == 5);
    CHECK(c[0] == "Velkacem");
    CHECK(c[2] == "Vel3id");
    CHECK(c[4] == "Arezqi");
    for (unsigned int i = 0; i < c.getSize(); i++)
        c[i] = c[i].append(" n at winat").data();
    CHECK(c[0] == "Velkacem n at winat");
    CHECK(c[2] == "Vel3id n at winat");
    CHECK(c[4] == "Arezqi n at winat");
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
    printableTests();

    return res; // + your_program_res
}
