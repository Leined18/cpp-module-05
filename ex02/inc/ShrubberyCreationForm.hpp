#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp" 

class ShrubberyCreationForm : public AForm
{ 
    private:
        virtual void execute(const Bureaucrat& executor) const;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif

