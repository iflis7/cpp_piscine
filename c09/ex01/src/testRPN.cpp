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

    SUBCASE("invalid expressions")
    {
        RPN rpn;
        CHECK_THROWS_MESSAGE(rpn.evaluate_rpn("1 & 1"), "Error: Invalid operator");

        RPN rpn1;
        CHECK_THROWS_MESSAGE(rpn1.evaluate_rpn("(1 + 1)"), "Error: Invalid operator");

        RPN rpn2;
        CHECK_THROWS_MESSAGE(rpn2.evaluate_rpn("10 0 /"), "Error: Division by zero");

        RPN rpn3;
        CHECK_THROWS_MESSAGE(rpn3.evaluate_rpn("1 2 3 +"), "Error: Invalid expression");

        RPN rpn4;
        CHECK_THROWS_MESSAGE(rpn4.evaluate_rpn("1 2 3 4 *"), "Error: Invalid expression");

        RPN rpn5;
        CHECK_THROWS_MESSAGE(rpn5.evaluate_rpn("a b c +"), "Error: Invalid token");

        RPN rpn6;
        CHECK_THROWS_MESSAGE(rpn6.evaluate_rpn("5 3 * +"), "Error: Insufficient operands");
    }
}

