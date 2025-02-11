#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Zombie
{
	private:
		std::string name;
	public:
	Zombie(std::string name);
    ~Zombie();
	void announce( void );
};
// Non-member functions (outside of the class)
Zombie* newZombie(std::string name);
void randomChump(std::string name);