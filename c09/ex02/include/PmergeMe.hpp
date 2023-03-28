#pragma once

#include "../../doctest.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"

class PergeMe
{
    std::vector<int> seq;
    std::vector<int> initialSeq;

    public:
        PergeMe();
        PergeMe(std::vector<int> seq);
        PergeMe(const PergeMe &rhs);
        ~PergeMe();
        PergeMe &operator=(const PergeMe &rhs);

        void setSequence(int argc, char **argv);
        const std::vector<int> getInitialSequence() const;
        const std::vector<int> getSortedSequence() const;
        void sort(std::vector<int> &seq);
        void insertion_sort(std::vector<int> &seq);
        void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& seq);
        void print(std::vector<int> seq);      
};

std::ostream &operator<<(std::ostream &out, const PergeMe &rhs);
