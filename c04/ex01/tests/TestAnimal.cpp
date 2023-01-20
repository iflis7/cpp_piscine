// #include "../../../Catch/include/catch.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <iostream>

using namespace std;

bool inOrder(const vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

TEST_CASE("My Tests", "[inOrder]")
{
    REQUIRE(inOrder({2, 3, 4, 10}) == true);
    REQUIRE(inOrder({12, 3, 4, 10}) == false);
}
