#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

#include "MyException.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();   

        // getters
        int         getGrade() const;
        std::string getName() const;

        // methods
        void        signForm(AForm &f);
        void        executeForm(AForm &f);
        void        incrementGrade(int amount = 1);
        void        decrementGrade(int amount = 1);

        class GradeTooHighException : public MyException {
        public:
            GradeTooHighException();
        };

        class GradeTooLowException : public MyException {
        public:
            GradeTooLowException();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif

