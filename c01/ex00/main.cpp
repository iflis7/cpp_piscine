#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie;

    // Create a zombie on the stack
 
    // Create a zombie on the heap
    heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    // Delete the heap zombie when we're done with it
    delete heapZombie;

    return (0);
}
