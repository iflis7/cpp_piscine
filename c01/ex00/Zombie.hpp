#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;
    // std::string _type;

public:
    // Zombie(std::string name, std::string type);
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);
};

// Function declarations
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
