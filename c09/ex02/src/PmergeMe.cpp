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
void PergeMe::sortVector(std::vector<int>& seq)
{
    const int threshold = 16;

    if (seq.size() <= 1)
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
}

void PergeMe::insertionSortVector(std::vector<int>& seq)
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

void PergeMe::mergeVector(std::vector<int>& left, std::vector<int>& right, std::vector<int>& seq)
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
void PergeMe::sortList(std::list<int>& seq)
{
    const int threshold = 16;

    if (seq.size() <= 1)
        return;
    else if (seq.size() < threshold)
        insertionSortList(seq);
    else
    {
        std::list<int> left, right;
        std::list<int>::iterator it = seq.begin();
        int n = seq.size() / 2;

        for (int i = 0; i < n; i++)
        {
            left.push_back(*it);
            it++;
        }

        while (it != seq.end())
        {
            right.push_back(*it);
            it++;
        }

        sortList(left);
        sortList(right);

        mergeList(left, right, seq);
    }
}

void PergeMe::insertionSortList(std::list<int>& seq)
{
    for (std::list<int>::iterator i = ++seq.begin(); i != seq.end(); i++)
    {
        std::list<int>::iterator j = i;
        int key = *i;

        while (j != seq.begin() && *(--j) > key)
        {
            *(j++) = *j;
        }

        *j = key;
    }
}

void PergeMe::mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& seq)
{
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();
    std::list<int>::iterator it_seq = seq.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            *it_seq = *it_left;
            it_left++;
        }
        else
        {
            *it_seq = *it_right;
            it_right++;
        }

        it_seq++;
    }

    while (it_left != left.end())
    {
        *it_seq = *it_left;
        it_left++;
        it_seq++;
    }

    while (it_right != right.end())
    {
        *it_seq = *it_right;
        it_right++;
        it_seq++;
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
    this->initialSeq = this->seq;
    this->initialSeqList = this->seqList;
}

const std::vector<int> PergeMe::getInitialVecSequence() const
{
    return (this->initialSeq);
}

const std::vector<int> PergeMe::getSortedVecSequence() const
{
    return (this->seq);
}

const std::list<int> PergeMe::getInitialListSequence() const
{
    return (this->initialSeqList);
}

const std::list<int> PergeMe::getSortedListSequence() const
{
    return (this->seqList);
}

void PergeMe::setProTime(double elapsedVectime, double elapsedListtime)
{
    this->vecProTime = elapsedVectime;
    this->listProTime = elapsedListtime;
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
    out << std::endl << std::endl;

    out << BOLD_GREEN << "After: " << RESET;
    for (unsigned long i = 0; i < seq.size(); i++)
    {
        out << seq[i] << " ";
    }
    out << std::endl;

    out << "Time to process a range of " << BOLD_CYAN << initSeq.size() << RESET << " elements with std::vector";
    return out;
}
