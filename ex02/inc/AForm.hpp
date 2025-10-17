#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "MyException.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool        isSigned;
        const int   gradeToSign; // required to sign it
        const int   gradeToExecute; // required to execute it
    public:
        AForm(void);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        ~AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);

        //methods
        void        beSigned(const Bureaucrat &b);
        
        // getters
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        bool        getIsSigned() const;
        std::string getName() const;
        
        virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public MyException {
            public:
            GradeTooHighException();
        };

        class GradeTooLowException : public MyException {
            public:
            GradeTooLowException();
        };
};

#endif

