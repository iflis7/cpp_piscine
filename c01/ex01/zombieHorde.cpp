#include "Zombie.hpp"

/**
 * @brief Create a Zombie object
 *
 * @param N The number of Zombies to create
 * @param name The name of the Zombies
 * @return Zombie* The pointer to the array of Zombies created(first element)
 */
Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombies[i] = Zombie(name);
    }
    return (zombies);
}
