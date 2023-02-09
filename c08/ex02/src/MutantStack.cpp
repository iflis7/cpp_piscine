#include "../include/MutantStack.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

class MutantStack
{
private:
    /* data */

public:
    MutantStack();
    ~MutantStack();
    MutantStack(MutantStack const &src);
    MutantStack &operator=(MutantStack const &rhs);
};
