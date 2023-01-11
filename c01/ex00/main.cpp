#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie;
	delete	heapZombie;

	// Create a zombie on the stack
	randomChump("Stack Zombie");
	// Create a zombie on the heap
	heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	// Delete the heap zombie when we're done with it
	return (0);
}

// NOTES ABOUT THE EXERCISE //
/*
The "randomChump" function creates a Zombie object on the stack because the object
is declared as a local variable within the function. When the function returns,
the object is automatically destroyed and the memory it occupied is released.
*/

/*
On the other hand,
	the newZombie function creates a Zombie object on the heap using the new operator.
The object is not automatically destroyed when the function returns,
	so it has a longer lifetime.
A pointer to the object is returned,
	and the caller is responsible for deleting the object
when it is no longer needed using the delete operator.
*/

/*
In general,
	it is more efficient to allocate objects on the stack if they have a short lifetime
and are only used within a single function.

If the object has a longer lifetime and needs to be accessed by multiple functions
or after the function it was created in has returned, it is generally better
to allocate it on the heap using new and store a pointer to it.
*/
