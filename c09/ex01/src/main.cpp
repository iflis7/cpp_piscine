#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/RPN.hpp"

void test()
{
    std::cout << "Test: 8 9 * 9 - 9 - 9 - 4 - 1 +" << std::endl;
    RPN rpn("8 9 * 9 - 9 - 9 - 4 - 1 +");
    rpn.getResult();

    std::cout << std::endl << "Test: 9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" 
        << std::endl;
    RPN rpn1("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -");
    rpn1.getResult();

    std::cout << std::endl << "Test: 1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" 
        << std::endl;
    RPN rpn2("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /");
    rpn2.getResult();

    std::cout << std::endl
              << "Test: 7 7 * 7 -" << std::endl;
    RPN rpn4("7 7 * 7 -");
    rpn4.getResult();
}

int main(int argc, char **argv)
{
    // // Doctest
    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if (ctx.shouldExit())             // query flags (and --exit) rely on this
        return res;                   // propagate the result of the tests
    std::cout << std::endl;
    if (argc == 2)
    {
        RPN rpn(argv[1]);
        std::cout << BOLD_MAGENTA << "Your Input: " << RESET;
        std::cout << std::endl
                  << argv[1] << std::endl;
        rpn.getResult();

        std::cout << std::endl
                  << BOLD_MAGENTA << "SUBJECT TESTS: " << RESET;
        std::cout << std::endl;
        test();
    }
    else
    {
        std::cout << "Usage: ./RPN <inverted Polish expression>" << std::endl;
        return 1;
    }
    return res; // + your_program_res
}
