#include "Zombie.hpp"

Zombie*zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;
	Zombie* horde;
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << i;
		horde[i].setName(name + oss.str());
	}
	return horde;
}