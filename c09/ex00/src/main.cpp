#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/BitcoinExchange.hpp"

// TEST_CASE("Test Vector")
// {

// }



int main(int argc, char **argv)
{
    doctest::Context ctx;
    // ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    // ctx.setOption("no-breaks", true); // override - don't break in the debugger
    // int res = ctx.run();              // run test cases unless with --no-run
    // if (ctx.shouldExit())             // query flags (and --exit) rely on this
    //     return res;                   // propagate the result of the tests
    // std::cout << std::endl;

    BitcoinExchange btc("data.csv");

    // return res; // + your_program_res
}
