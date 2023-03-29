#include "../include/PmergeMe.hpp"

PergeMe::PergeMe()
{
}

PergeMe::PergeMe(std::vector<int> seq)
{
    this->seq = seq;
}

PergeMe::PergeMe(const PergeMe &rhs)
{
    if (this != &rhs)
        this->seq = rhs.seq;
}

PergeMe::~PergeMe()
{
}

PergeMe &PergeMe::operator=(const PergeMe &rhs)
{
    if (this != &rhs)
        this->seq = rhs.seq;
    return *this;
}

/* Sorting Vector Container */
void PergeMe::sortVector(std::vector<int> &seq)
{
    const int threshold = 16;

    if (seq.size() < 2)
        return;
    else if (seq.size() < threshold)
        insertionSortVector(seq);
    else
    {
        std::vector<int> left(seq.begin(), seq.begin() + seq.size() / 2);
        std::vector<int> right(seq.begin() + seq.size() / 2, seq.end());

        sortVector(left);
        sortVector(right);

        mergeVector(left, right, seq);
    }
    setSortedVecSequence(seq);
}

void PergeMe::insertionSortVector(std::vector<int> &seq)
{
    for (int i = 1; i < static_cast<int>(seq.size()); i++)
    {
        int key = seq[i];
        int j = i - 1;
        while (j >= 0 && seq[j] > key)
        {
            seq[j + 1] = seq[j];
            j--;
        }
        seq[j + 1] = key;
    }
}

void PergeMe::mergeVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &seq)
{
    int i = 0, j = 0, k = 0;

    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size()))
    {
        if (left[i] < right[j])
            seq[k++] = left[i++];
        else
            seq[k++] = right[j++];
    }

    while (i < static_cast<int>(left.size()))
    {
        seq[k++] = left[i++];
    }

    while (j < static_cast<int>(right.size()))
    {
        seq[k++] = right[j++];
    }
}

/* Sorting List Container */
void PergeMe::sortList(std::list<int> &seq)
{
    const int threshold = 16;
    int j = 0;

    if (seq.size() < 2)
        return;
    else if (seq.size() < threshold)
        insertionSortList(seq);
    else
    {
        std::list<int> left, right;
        std::list<int>::iterator it = seq.begin();
        for (int i = 0; i < static_cast<int>(seq.size()) / 2; i++)
        {
            // std::cout << "i--: " << i << std::endl;
            // std::cout << "seq.size()--: " << seq.size() << std::endl;
            left.push_back(*it);
            it++;
            // std::cout << "loop: " << std::endl;
            j = i;
        }
        std::cout << "it: " << *it << std::endl;
        std::cout << "J: " << j << std::endl;
        // for (int i = (static_cast<int>(seq.size()) / 2); i < static_cast<int>(seq.size()); i++)
        // {
        //     // std::cout << "i: " << i << std::endl;
        //     // std::cout << "seq.size(): " << seq.size() << std::endl;
        //     right.push_back(*it);
        //     it++;
        //     // std::cout << "loop: " << std::endl;
        //     // std::cout << "It: " << *it << std::endl;
        // }
        while (it != seq.end())
        {
            right.push_back(*it);
            it++;
            // std::cout << "loop1: " << std::endl;
            // std::cout << "It: " << *it << std::endl;
            // std::cout << "seq.size(): " << seq.size() << std::endl;
        }

        sortList(left);
        sortList(right);

        mergeList(left, right, seq);
    }
    setSortedListSequence(seq);
}

void PergeMe::insertionSortList(std::list<int> &seq)
{
    for (std::list<int>::iterator i = seq.begin(); i != seq.end(); i++)
    {
        std::list<int>::iterator j = i;
        while (j != seq.begin() && *(j--) > *i);
        seq.insert(++j, *i);
        i = seq.erase(i); // Update i to point to the next element
    }
}

void PergeMe::mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &seq)
{
    std::list<int>::iterator i = left.begin(), j = right.begin();

    while (i != left.end() && j != right.end())
    {
        if (*i < *j)
        {
            seq.push_back(*i);
            i++;
        }
        else
        {
            seq.push_back(*j);
            j++;
        }
    }
    while (i != left.end())
    {
        seq.push_back(*i);
        i++;
    }
    while (j != right.end())
    {
        seq.push_back(*j);
        j++;
    }
}


void PergeMe::setSequence(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) > 0)
        {
            this->seq.push_back(atoi(argv[i]));
            this->seqList.push_back(atoi(argv[i]));
        }
        else
        {
            std::cout << "Invalid input: " << argv[i] << std::endl;
            exit(1);
        }
    }
    if(hasDuplicates(this->seq))
    {
        std::cout << "Invalid input: duplicate values" << std::endl;
        exit(1);
    }
    this->initialSeq = this->seq;
    this->initialSeqList = this->seqList;
}

bool PergeMe::hasDuplicates(std::vector<int>& seq)
{
    for (int i = 0; i < static_cast<int>(seq.size()); i++)
    {
        for (int j = i + 1; j < static_cast<int>(seq.size()); j++)
        {
            if (seq[i] == seq[j])
                return true;
        }
    }
    return false;
}

const std::vector<int> PergeMe::getInitialVecSequence() const
{
    return (this->initialSeq);
}

const std::vector<int> PergeMe::getSortedVecSequence() const
{
    return (this->seq);
}

void PergeMe::setSortedVecSequence(std::vector<int> seq)
{
    this->seq = seq;
}

const std::list<int> PergeMe::getInitialListSequence() const
{
    return (this->initialSeqList);
}

const std::list<int> PergeMe::getSortedListSequence() const
{
    return (this->seqList);
}

void PergeMe::setSortedListSequence(std::list<int> seq)
{
    this->seqList = seq;
}

void PergeMe::setProTime(double elapsedVectime, double elapsedListtime)
{
    this->vecProTime = elapsedVectime;
    this->listProTime = elapsedListtime;
}

double PergeMe::getVecProTime() const
{
    return (this->vecProTime);
}

double PergeMe::getListProTime() const
{
    return (this->listProTime);
}

std::ostream &operator<<(std::ostream &out, const PergeMe &rhs)
{
    std::vector<int> seq = rhs.getSortedVecSequence();
    std::vector<int> initSeq = rhs.getInitialVecSequence();
    std::list<int> listSeq = rhs.getSortedListSequence();
    std::list<int> initListSeq = rhs.getInitialListSequence();

    out << BOLD_YELLOW << "Before: " << RESET;
    for (unsigned long i = 0; i < initSeq.size(); i++)
    {
        out << initSeq[i] << " ";
    }
    out << std::endl;

    out << BOLD_GREEN << "After: " << RESET;
    for (unsigned long i = 0; i < seq.size(); i++)
    {
        out << seq[i] << " ";
    }
    out << std::endl;

    out << "Time to process a range of " << BOLD_CYAN << initSeq.size() << RESET << " elements with std::vector: " 
            << BOLD_CYAN << std::fixed << std::setprecision(6) << rhs.getVecProTime() << " us" << RESET << std::endl;

    out << "Time to process a range of " << BOLD_CYAN << listSeq.size() << RESET << " elements with std::[list]: " 
            << BOLD_CYAN << std::fixed << std::setprecision(6) << rhs.getListProTime() << " us" << RESET << std::endl;
    return out;
}



// void PergeMe::printSeq(std::vector<int> &seq)
// {
//     for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
//     {
//         std::cout << BOLD_BLUE << *it << " " << RESET;
//     }
//     std::cout << std::endl;
// }

// void PergeMe::printSeqMid(std::vector<int> &seq)
// {
//     for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
//     {
//         std::cout << BOLD_YELLOW << *it << " " << RESET;
//     }
//     std::cout << std::endl;
// }

// void PergeMe::printSeqAft(std::vector<int> &seq)
// {
//     for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
//     {
//         std::cout << BOLD_RED << *it << " " << RESET;
//     }
//     std::cout << std::endl;
// }
