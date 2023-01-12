#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Bob");

    clapTrap.attack("bad guy");
    clapTrap2.attack("bad guy");
    clapTrap2.takeDamage(3);
    clapTrap2.beRepaired(1);

    std::cout << std::endl;
    
    ScavTrap scavTrap;
    ScavTrap scavTrap2("John");

    scavTrap.attack("bad guy");
    clapTrap2.attack("bad guy");
    scavTrap2.guardGate();

    return 0;
}
