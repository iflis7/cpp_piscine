#include "../include/Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    PresidentialPardonForm();

public:
    // Constructors
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);

    // Assignment operator overload
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    // Destructor
    ~PresidentialPardonForm();

    void action(const Bureaucrat &executor) const;
};
