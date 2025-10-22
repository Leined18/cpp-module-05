#include "FormFactory.hpp"

const char* FormFactory::_formNames[FormFactory::_maxForms];
FormFactory::Creator FormFactory::_creators[FormFactory::_maxForms];
int FormFactory::_count = 0;

AForm* FormFactory::createForm(const char* name, const std::string& target) {
    for (int i = 0; i < _count; ++i) {
        if (std::strcmp(_formNames[i], name) == 0) {
            return _creators[i](target);
        }
    }
    return NULL;
}


bool FormFactory::registerForm(const char *name, Creator creator) {
    if (_count >= _maxForms) return false;
    _formNames[_count] = name;
    _creators[_count] = creator;
    ++_count;
    return true;
}

// Default constructor
FormFactory::FormFactory(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
FormFactory::FormFactory(const FormFactory &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
FormFactory &FormFactory::operator=(const FormFactory &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
FormFactory::~FormFactory(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

