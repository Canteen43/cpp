#include <string>
#include <sstream>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Zombie
{
	private:
		std::string name;
	public:
	Zombie();
    ~Zombie();
	void announce( void );
	void setName(std::string newName);
};
// Non-member functions (outside of the class)
Zombie*zombieHorde( int N, std::string name );
