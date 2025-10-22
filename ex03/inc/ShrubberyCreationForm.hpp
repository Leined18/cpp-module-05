#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp" 
#include "FormFactory.hpp"

class ShrubberyCreationForm : public AForm
{ 
    private:
        virtual void execute(const Bureaucrat& executor) const;
        static bool _registered;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        static AForm* create(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif

