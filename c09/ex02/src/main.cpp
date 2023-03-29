#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/PmergeMe.hpp"


// TEST_CASE("PmergeMe Tests")
// {

// }

int main(int argc, char **argv)
{
    // doctest::Context ctx;
    // ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    // ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    // ctx.setOption("no-breaks", true); // override - don't break in the debugger
    // int res = ctx.run();              // run test cases unless with --no-run
    // if (ctx.shouldExit())             // query flags (and --exit) rely on this
    //     return res;                   // propagate the result of the tests
    // std::cout << std::endl;
    // (void)argc;

    if(argc < 3)
    {
        std::cout << "Usage: ./PmergeMe <int int int> " << std::endl;
        return 1;
    }
    PergeMe pergeMe;
    pergeMe.setSequence(argc, argv);
    std::vector<int> seq = pergeMe.getInitialVecSequence();
    clock_t start_time = clock();
    pergeMe.sortVector(seq);
    clock_t end_time = clock();
    float elapsedVectime = float(end_time - start_time) / CLOCKS_PER_SEC;

    // pergeMe.printSeq(seq);
    std::list<int> seqList = pergeMe.getInitialListSequence();
    start_time = clock();
    pergeMe.sortList(seqList);
    end_time = clock();
    double elapsedListtime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    pergeMe.setProTime(elapsedVectime, elapsedListtime);

    std::cout << pergeMe << std::endl;

    // return res; // + your_program_res
}
