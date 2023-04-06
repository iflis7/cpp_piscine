#include "../../doctest.hpp"
#include "../include/BitcoinExchange.hpp"

TEST_CASE("BitcoinExchange tests")
{
    BitcoinExchange btc;

    SUBCASE("validDateFormat")
    {
        CHECK(btc.validDateFormat("2022-03-01") == true);
        CHECK(btc.validDateFormat("2009-01-01") == true);
        CHECK(btc.validDateFormat("2023-13-01") == false);
        CHECK(btc.validDateFormat("2023-03-32") == false);
        CHECK(btc.validDateFormat("202-03-01") == false);
        CHECK(btc.validDateFormat("2022/03/01") == false);
        CHECK(btc.validDateFormat("") == false);
    }

    SUBCASE("validValueFormat")
    {
        CHECK(btc.validValueFormat(0.0f, "2022-03-01") == true);
        CHECK(btc.validValueFormat(100.0f, "2022-03-01") == true);
        CHECK(btc.validValueFormat(-100.0f, "2022-03-01") == false);
        CHECK(btc.validValueFormat(std::string::npos, "2022-03-01") == false);
        CHECK(btc.validValueFormat(10000.0f, "2022-03-01") == false);
    }

    SUBCASE("trim")
    {
        CHECK(btc.trim("") == "");
        CHECK(btc.trim(" ") == "");
        CHECK(btc.trim("\t") == "");
        CHECK(btc.trim(" \t ") == "");
        CHECK(btc.trim("   test   ") == "test");
        CHECK(btc.trim("  test  \t ") == "test");
    }

    SUBCASE("getCsvInfo")
    {
        std::string file1 = "src/data.csv";
        std::deque<std::pair<std::string, float> > csvInfo = btc.getCsvInfo(file1);
        CHECK(csvInfo.size() == 1612);
        CHECK(csvInfo[0].first == "2009-01-02");
        // CHECK(csvInfo[0].second == 0);
        CHECK(csvInfo[300].first == "2011-06-22");
        CHECK(csvInfo[300].second == 15.39f);
    }


    SUBCASE("getInputInfo")
    {
        std::string file = "src/testInput.txt";
        std::deque<std::pair<std::string, float> > inputInfo = btc.getInputInfo(file);
        // CHECK(inputInfo.size() == 15);
        // CHECK(inputInfo[0].first == "2010-08-20");
        // CHECK(inputInfo[0].second == 3);
        // CHECK(inputInfo[1].first == "2011-03-02");
        // CHECK(inputInfo[1].second == 2);
    }

    SUBCASE("nearestDate")
    {
        std::string file1 = "src/data.csv";
        std::deque<std::pair<std::string, float> > csvInfo = btc.getCsvInfo(file1);
        std::pair<std::string, float> nearest = nearestDate("2022-03-31", csvInfo);
        CHECK(nearest.first == "2022-03-29");

        nearest = nearestDate("2013-01-16", csvInfo);
        CHECK(nearest.first == "2013-01-14");

        nearest = nearestDate("2019-09-27", csvInfo);
        CHECK(nearest.first == "2019-09-26");

        nearest = nearestDate("2008-01-02", csvInfo);
        CHECK(nearest.first == "2009-01-02");

        // CHECK(inputInfo[0].first == "2010-08-20");
        // CHECK(inputInfo[0].second == 3);
        // CHECK(inputInfo[1].first == "2011-03-02");
        // CHECK(inputInfo[1].second == 2);
    }
}
