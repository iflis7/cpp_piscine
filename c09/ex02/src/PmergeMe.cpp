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

void PergeMe::sort(std::vector<int>& seq)
{
    const int threshold = 16;

    if (seq.size() <= 1)
        return;
    else if (seq.size() < threshold)
        insertion_sort(seq);
    else
    {
        std::vector<int> left(seq.begin(), seq.begin() + seq.size() / 2);
        std::vector<int> right(seq.begin() + seq.size() / 2, seq.end());

        sort(left);
        sort(right);

        merge(left, right, seq);
    }
}

void PergeMe::insertion_sort(std::vector<int>& seq)
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

void PergeMe::merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& seq)
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

void PergeMe::setSequence(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) > 0)
            this->seq.push_back(atoi(argv[i]));
        else
        {
            std::cout << "Invalid input: " << argv[i] << std::endl;
            exit(1);
        }
    }
    this->initialSeq = this->seq;
}

const std::vector<int> PergeMe::getInitialSequence() const
{
    return (this->initialSeq);
}

const std::vector<int> PergeMe::getSortedSequence() const
{
    return (this->seq);
}

std::ostream &operator<<(std::ostream &out, const PergeMe &rhs)
{
    std::vector<int> seq = rhs.getSortedSequence();
    std::vector<int> initSeq = rhs.getInitialSequence();
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

    out << "Time to process a range of " << initSeq.size() << "elements with std::vector"
    return out;
}
