#include "../include/PmergeMe.hpp"

TEST_CASE("PergeMe constructor with vector argument")
{
    std::vector<int> vect;
    std::list<int> lst;

    for (int i = 300; i > 1; i--)
    {
        vect.push_back(i);
    };
    for (int i = 300; i > 1; i--)
    {
        lst.push_back(i);
    };

    PergeMe pergeMe(vect);
    CHECK(!std::is_sorted(vect.begin(), vect.end()));
    pergeMe.sortVector(vect);
    CHECK(std::is_sorted(vect.begin(), vect.end()));

    CHECK(!std::is_sorted(lst.begin(), lst.end()));
    pergeMe.sortList(lst);
    CHECK(std::is_sorted(lst.begin(), lst.end()));
}

TEST_CASE("PergeMe constructor with list argument")
{
    std::vector<int> vect;
    std::list<int> lst;

    for (int i = 1000; i > 1; i--)
    {
        vect.push_back(i);
    };
    for (int i = 100; i > 1; i--)
    {
        lst.push_back(i);
    };

    PergeMe pergeMe(vect);
    CHECK(!std::is_sorted(vect.begin(), vect.end()));
    pergeMe.sortVector(vect);
    CHECK(std::is_sorted(vect.begin(), vect.end()));

    CHECK(!std::is_sorted(lst.begin(), lst.end()));
    pergeMe.sortList(lst);
    CHECK(std::is_sorted(lst.begin(), lst.end()));
}

