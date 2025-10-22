#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp" 


class RobotomyRequestForm : virtual public AForm
{
    private:
        virtual void execute(const Bureaucrat& executor) const;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f);

#endif

