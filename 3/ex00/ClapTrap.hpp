#include <string>
class ClapTrap
{
	// It will be called ClapTrap and will have the following private attributes initialized
	// to the values specified in brackets:
	private:
	// •Name, which is passed as parameter to a constructor
		std::string name;
	// •Hit points (10), represent the health of the ClapTrap
		unsigned int hitpoints;
	// •Energy points (10)
		unsigned int energy_points;
	// •Attack damage (0)
		unsigned int attack_damage;
	public:
	// Add the following public member functions so the ClapTrap looks more realistic:
	// •void attack(const std::string& target);
	void attack(const std::string& target);
	// •void takeDamage(unsigned int amount);
	void takeDamage(unsigned int amount);
	// •void beRepaired(unsigned int amount);
	void beRepaired(unsigned int amount);
	// My extra functions:
	// Default constructor
	ClapTrap();
	// Parametric Constructor:
	ClapTrap(std::string set_name);
	// Copy constructor
	ClapTrap(const ClapTrap& other);
	// Copy assignment operator:
	ClapTrap& operator=(const ClapTrap& other);
	// Destructor:
	~ClapTrap();
	// Debug:
	void printStatus();	
};