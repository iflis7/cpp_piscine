#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object on the stack and calls its announce method
 *
 * @param name The name of the Zombie
 */
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
