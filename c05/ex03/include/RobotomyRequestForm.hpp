#include "../include/Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    RobotomyRequestForm();

public:
    // Constructors
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);

    // Assignment operator overload
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    // Destructor
    ~RobotomyRequestForm();

    void action(const Bureaucrat &executor) const;
};
