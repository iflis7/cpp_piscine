#include "Zombie.hpp"

int main(void)
{
    //Create a horde of Zombies and test them
    Zombie *zombies = zombieHorde(5, "Bob");

    // Announce the horde one by one
    for (int i = 0; i < 5; i++)
    {
        zombies[i].announce();
    }

    // Delete the horde
    delete [] zombies;

    return (0);
}
