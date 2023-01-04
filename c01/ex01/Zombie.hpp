#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iomanip>

/**
 * @brief Zombie class
 *
 * @param _name The name of the Zombie
 * @method Zombie(void) Default constructor
 * @method Zombie(std::string name) Constructor
 * @method ~Zombie(void) Destructor
 * @method void announce(void) Announce the Zombie
 */
class Zombie
{

private:
    std::string _name;

public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);
};

// The function that creates a horde of N Zombies
Zombie *zombieHorde(int N, std::string name);

#endif
