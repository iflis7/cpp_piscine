#include "Zombie.hpp"

int main(void)
{
    int num = 5;
    // Create a horde of Zombies and test them
    Zombie *zombies = zombieHorde(num, "Bob");

    // Announce the horde one by one
    for (int i = 0; i < num; i++)
    {
        zombies[i].announce();
    }

    // Delete the horde
    delete[] zombies;

    return (0);
}
