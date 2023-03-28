#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/BitcoinExchange.hpp"

// TEST_CASE("Test Vector")
// {

// }

int main(int argc, char **argv)
{
    // (void)argc;
    // (void)argv;
    // doctest::Context ctx;
    // ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    // ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    // ctx.setOption("no-breaks", true); // override - don't break in the debugger
    // int res = ctx.run();              // run test cases unless with --no-run
    // if (ctx.shouldExit())             // query flags (and --exit) rely on this
    //     return res;                   // propagate the result of the tests
    // std::cout << std::endl;

    if (argc == 2)
    {
        BitcoinExchange btc("src/data.csv", argv[1]);
        btc.run();
    }
    else
        std::cout << "Usage: ./btc [file]" << std::endl;
    return (0);
    // return res; // + your_program_res
}
