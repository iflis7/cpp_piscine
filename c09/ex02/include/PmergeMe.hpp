#pragma once

#include "../../doctest.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <list>

#define RESET "\033[0m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN "\033[1m\033[36m"

class PergeMe
{
    std::vector<int> seq;
    std::vector<int> initialSeq;

    std::list<int> seqList;
    std::list<int> initialSeqList;

    double proVecTime;
    double proListTime;

    public:
        PergeMe();
        PergeMe(std::vector<int> seq);
        PergeMe(const PergeMe &rhs);
        ~PergeMe();
        PergeMe &operator=(const PergeMe &rhs);

        void setSequence(int argc, char **argv);
        bool hasDuplicates(std::vector<int>& seq);
        
        // SORTING WITH VECTORS
        const std::vector<int> getInitialVecSequence() const;
        const std::vector<int> getSortedVecSequence() const;
        void setSortedVecSequence(std::vector<int> seq);
        void printVecSeq(std::vector<int> &seq) const;
                
        void sortVector(std::vector<int> &seq);
        void insertionSortVector(std::vector<int> &seq);
        void mergeVector(std::vector<int>& left, std::vector<int>& right, std::vector<int>& seq);

        // SORTING WITH LISTS
        const std::list<int> getInitialListSequence() const;
        const std::list<int> getSortedListSequence() const;
        void setSortedListSequence(std::list<int> seq);
        void printListSeq(std::list<int> &listSeq) const;

        void sortList(std::list<int> &seq);
        void insertionSortList(std::list<int> &seq);
        void mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& seq);

        // MANAGING PROCESSING TIME
        void setProTime(double elapsedVecTime, double elapsedListTime);
        double getVecProTime() const;
        double getListProTime() const;
};


std::ostream &operator<<(std::ostream &out, const PergeMe &rhs);
