#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Bob");

    clapTrap.attack("bad guy");
    clapTrap2.takeDamage(3);
    clapTrap2.beRepaired(1);

    std::cout << std::endl;
    FragTrap fragtrap;
    FragTrap fragtrap2("John");

    fragtrap.attack("bad guy");
    fragtrap2.highFivesGuys();

    return 0;
}
