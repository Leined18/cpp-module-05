#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

#include "MyException.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        MyException e;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();   

        int         getGrade() const;
        std::string getName() const;
        void        incrementGrade();
        void        decrementGrade();
        void        incrementGrade(int n);
        void        decrementGrade(int n);
};

void        testDecrement(Bureaucrat &b, int n);
void        testIncrement(Bureaucrat &b, int n);

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif

