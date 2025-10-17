#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "MyException.hpp"
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool        isSigned;
        const int   gradeToSign; // required to sign it
        const int   gradeToExecute; // required to execute it
    public:
        Form(void);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);

        //methods
        void        beSigned(const Bureaucrat &b);
        
        // getters
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        bool        getIsSigned() const;
        std::string getName() const;
        

        class GradeTooHighException : public MyException {
            public:
            GradeTooHighException();
        };

        class GradeTooLowException : public MyException {
            public:
            GradeTooLowException();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

