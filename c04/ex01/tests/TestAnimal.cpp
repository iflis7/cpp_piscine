// #include "../../../Catch/include/catch.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <iostream>

// This is the function we want to test
int add(int a, int b) {
    return a + b;
}

TEST_CASE("Adding two numbers", "[add]") {
    REQUIRE(add(1, 2) == 3);
    REQUIRE(add(2, 2) == 4);
    REQUIRE(add(-1, 2) == 1);
    REQUIRE(add(0, 0) == 0);
}
