#include "Harl.hpp"

/**
 * @brief Construct a new Harl:: Harl object
 *
 */
Harl::Harl()
{
    cout << "Harl:: Created!" << endl;
    cout << endl;
}

/**
 * @brief Destroy the Harl:: Harl object
 *
 */
Harl::~Harl()
{
    cout << endl;
    cout << "Harl:: Destroyed!" << endl;
}

/**
 * @brief Debugging the burger
 *
 * @param level
 */
void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    cout << endl;
}

/**
 * @brief Info about the burger
 *
 */
void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    cout << endl;
}

/**
 * @brief Warning about the burger
 *
 */
void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    cout << endl;
}

/**
 * @brief Error about the burger
 *
 */
void Harl::error()
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
    cout << endl;
}

/**
 * @brief Complain about the burger
 *
 * @param level The level of complaint
 */
void Harl::complain(std::string level)
{
    // Define an array of pointers to member functions
    void (Harl::*levels[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // Define an array of strings representing the levels
    std::string levelStrings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Find the index of the level in the levelStrings array
    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levelStrings[i])
        {
            index = i;
            break;
        }
    }

    // Call the appropriate member function using the index
    switch (index)
    {
    case 0:
        for (int i = index; i < 4; i++)
            (this->*levels[i])();
        break;
    case 1:
        for (int i = index; i < 4; i++)
            (this->*levels[i])();
        break;
    case 2:
        // // (this->*levels[0])();
        // (this->*levels[1])();
        // (this->*levels[2])();
        break;
    case 3:
        // (this->*levels[0])();
        // (this->*levels[1])();
        (this->*levels[2])();
        (this->*levels[3])();
        break;
    default:
        // Do nothing
        break;
    }
}
