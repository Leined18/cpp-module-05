#include "PresidentialPardonForm.hpp"

// To Complete
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    (void)executor;
    std::cout << GREEN << target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void):AForm()
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm",  25, 5, target)
{
    return ;
}


// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
AForm(other)
{
    (void) other;
    return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{

    (void) other;
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f)
{
    os << static_cast<const AForm&>(f) // usa el bonito de AForm
       << "\n   " << MAGENTA << "• Target: " << RESET << f.getTarget(); // TARGET
    return os;
}
