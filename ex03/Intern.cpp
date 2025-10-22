#include "Intern.hpp"

AForm* Intern::makeForm(const std::string name, const std::string target) {
    AForm* form = FormFactory::createForm(name.c_str(), target);
    if (form) {
        std::cout << "Intern creates " << name << std::endl;
    } else {
        std::cerr << "Intern: Unknown form name \"" << name << "\"" << std::endl;
    }
    return form;
}

// Default constructor
Intern::Intern(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Intern::~Intern(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

