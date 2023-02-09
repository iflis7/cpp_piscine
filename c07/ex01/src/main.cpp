#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/Iter.hpp"

TEST_CASE("Scalar Test Int Array")
{
    std::cout << std::setw(30) << " ============ Test Case 1 ============ " << std::endl;
    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int copyArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int value = 7;
    iter(intArr, 13, Adder<int>(value)); // iterate and add 7 to each array value
    for (int i = 0; i < 13; i++)
    {
        std::cout << intArr[i] << " ";
        CHECK(intArr[i] == copyArr[i] + 7); // check that every value equals the old + 7
    }
    std::cout << std::endl;
}

TEST_CASE("Scalar Test Float Array")
{
    std::cout << std::setw(30) << " ============ Test Case 2 ============ " << std::endl;
    float fltArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    float copyArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    float value = 7.0;
    iter(fltArr, 5, Adder<float>(value)); // iterate and add 7 to each array value
    for (int i = 0; i < 5; i++)
    {
        std::cout << fltArr[i] << " ";
        CHECK(fltArr[i] == copyArr[i] + 7.0f); // check that every value equals the old + 7
    }
    std::cout << std::endl;
}

int test()
{
    std::cout << std::setw(30) << " ============ Test ============ " << std::endl;
    float arr2[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    int value = 2.0;
    std::cout << "First array : ";
    iter(arr2, 5, print<float>);
    iter(arr2, 5, Adder<float>(value));

    std::cout << std::endl
              << "Second array: ";
    iter(arr2, 5, print<float>);
    std::cout << std::endl;
    return 0;

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
