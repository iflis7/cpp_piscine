#include "Zombie.hpp"

/**
 * @brief creates a new Zombie object on the heap using the new operator
 *   and returns a pointer to it
 * @param name The name of the Zombie
 * @return Zombie* The pointer to the new Zombie object
 */
Zombie *newZombie(std::string name)
{
    Zombie *zombie;

    zombie = new Zombie(name);
    return (zombie);
}
