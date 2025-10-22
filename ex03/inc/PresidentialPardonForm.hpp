#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp" 
#include "FormFactory.hpp"

class PresidentialPardonForm : virtual public AForm
{
    private:
        virtual void execute(const Bureaucrat& executor) const;
        static bool _registered;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        static AForm* create(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f);


#endif

