#include "../include/DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap()
{
    this->_name = "Default";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Constructor for the name " << this->_name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    this->_name = src._name + "_clap_trap";
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Hello i am a DiamondTrap named " << this->_name << " and i am originated from the ClapTrap named " << ClapTrap::_name << "." << std::endl;
}
