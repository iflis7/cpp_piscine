#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Harl class
 *
 */
class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();
    void complain(string level);
};

#endif
