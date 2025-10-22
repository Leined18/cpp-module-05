#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "MyException.hpp"
# include "FormFactory.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
};

#endif

