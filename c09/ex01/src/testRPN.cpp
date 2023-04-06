#include "../include/RPN.hpp"

TEST_CASE("RPN tests")
{
    SUBCASE("valid expressions")
    {
        RPN rpn("3 4 + 2 *");
        CHECK(rpn.evaluate_rpn("3 4 + 2 *") == 14);

        RPN rpn2("5 3 - 4 *");
        CHECK(rpn2.evaluate_rpn("5 3 - 4 *") == 8);

        RPN rpn3("7 2 /");
        CHECK(rpn3.evaluate_rpn("7 2 /") == 3);
    }
}

