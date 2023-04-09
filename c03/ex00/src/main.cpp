#include "../include/ClapTrap.hpp"

#include <vector>

/*
It will be called ClapTrap and will have the following private attributes initialized
to the values specified in brackets:

•Name, which is passed as parameter to a constructor
•Hit points (10), represent the health of the ClapTrap
•Energy points (10)
•Attack damage (0)

Add the following public member functions so the ClapTrap looks more realistic:

•void attack(const std::string& target);
•void takeDamage(unsigned int amount);
•void beRepaired(unsigned int amount);

When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.

In all of these member functions, you have to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):

ClapTrap <name> attacks <target>, causing <damage> points of damage!

The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.

Implement and turn in your own tests to ensure your code works as expected.
*/

int main(void)
{
    ClapTrap clap("Dave");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    return (0);

    std::vector<int> vecInt;
    std::vector<std::string> vecStr;
    std::vector<ClapTrap> vecClap;

    vecInt.push_back(1);
    // vecClap.push_back();




}
