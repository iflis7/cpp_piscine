#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    /* Should print:
        Bob attacks with his crude spiked club
        Bob attacks with his some other type of club
    */
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    /* Should print:
        Jim attacks with their crude spiked club
        Jim attacks with their some other type of club
    */
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    /*
        Should print:
        Dave is unarmed and cannot attack
    */
    std::cout << std::endl;
    {
        HumanB dave("Dave");
        dave.attack();
    }
    return 0;
}
