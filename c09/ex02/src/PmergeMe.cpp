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

bool validInput(char **argv)
{
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cout << BOLD_RED << "Invalid input: " << RESET << argv[i][j] << std::endl; // TODO fix the 0 error
                exit(1);
            }
        }
    }
    return (true);
}



void PergeMe::setSequence(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        // std::cout << BOLD_YELLOW << "0 is considered positive"  << std::endl;
        if (std::atoi(argv[i]) > 0)
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

/* Sorting VECTOR Container */
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

void PergeMe::printVecSeq(std::vector<int> &seq) const
{
    for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
    {
        std::cout << *it << " " << RESET;
    }
    std::cout << std::endl;
}

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



/* Sorting LIST Container */
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

void PergeMe::printListSeq(std::list<int> &listSeq) const
{
    for (std::list<int>::iterator it = listSeq.begin(); it != listSeq.end(); it++)
    {
        std::cout << BOLD_BLUE << *it << " " << RESET;
    }
    std::cout << std::endl;
}

void PergeMe::insertionSortList(std::list<int> &seq)
{
    for (std::list<int>::iterator i = seq.begin(); i != seq.end(); ++i)
    {
        int key = *i;
        std::list<int>::iterator j = i;
        j--;
        while (j != seq.begin() && *j > key)
        {
            std::list<int>::iterator jNext = j;
            jNext++;
            *jNext = *j;
            j--;
        }
        std::list<int>::iterator jNext = j;
        jNext++;
        *jNext = key;
    }
    std::list<int>::iterator i = seq.begin();
    int key = *i;
    seq.pop_front();
    seq.push_back(key);
}

void PergeMe::mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &seq)
{
    std::list<int>::iterator i = left.begin(), j = right.begin();

    while (i != left.end() && j != right.end())
    {
        if (*i < *j)
        {
            seq.push_back(*i);
            seq.pop_front();
            i++;
        }
        else
        {
            seq.push_back(*j);
            seq.pop_front();
            j++;
        }
    }
    while (i != left.end())
    {
        seq.push_back(*i);
        seq.pop_front();
        i++;
    }
    while (j != right.end())
    {
        seq.push_back(*j);
        seq.pop_front();
        j++;
    }
}

void PergeMe::sortList(std::list<int> &seq)
{
    const int threshold = seq.size() / 4;

    if (seq.size() < 2)
        return;
    else if (seq.size() < static_cast<unsigned long>(threshold))
        insertionSortList(seq);
    else
    {
        std::list<int> left, right;
        std::list<int>::iterator middle = seq.begin();
        std::advance(middle, seq.size() / 2);

        std::copy(seq.begin(), middle, std::back_inserter(left));
        std::copy(middle, seq.end(), std::back_inserter(right));

        sortList(left);
        sortList(right);

        mergeList(left, right, seq);
    }

    setSortedListSequence(seq);
}

bool PergeMe::hasDuplicates(std::vector<int> &seq)
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



// // MANAGING PROCESSING TIME
double PergeMe::getVecProTime() const
{
    return (this->proVecTime);
}

double PergeMe::getListProTime() const
{
    return (this->proListTime);
}

void PergeMe::setProTime(double elapsedVecTime, double elapsedListTime)
{
    this->proVecTime = elapsedVecTime;
    this->proListTime = elapsedListTime;
}

std::ostream &operator<<(std::ostream &out, const PergeMe &rhs)
{
    std::vector<int> seq = rhs.getSortedVecSequence();
    std::vector<int> initSeq = rhs.getInitialVecSequence();
    std::list<int> listSeq = rhs.getSortedListSequence();
    std::list<int> initListSeq = rhs.getInitialListSequence();

    out << BOLD_YELLOW << "Before: " << RESET;
    rhs.printVecSeq(initSeq);
    out << BOLD_GREEN << "After: " << RESET;
    rhs.printVecSeq(seq);
    out << std::endl;

    out << BOLD_YELLOW << "Before: " << RESET;
    rhs.printListSeq(initListSeq);
    out << BOLD_GREEN << "After: " << RESET;
    rhs.printListSeq(listSeq);
    out << std::endl;

    out << "Time to process a range of " << BOLD_CYAN << initSeq.size() << RESET << " elements with std::vector: "
        << BOLD_CYAN << std::fixed << std::setprecision(6) << rhs.getVecProTime() << " us" << RESET << std::endl;

    out << "Time to process a range of " << BOLD_CYAN << initSeq.size() << RESET << " elements with std::[list]: "
        << BOLD_CYAN << std::fixed << std::setprecision(6) << rhs.getListProTime() << " us" << RESET << std::endl;
    return out;
}

