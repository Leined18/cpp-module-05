#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "MyException.hpp"
#include <fstream>
#include <cstdlib>

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

class Bureaucrat;

class AForm
{
    protected:
        const       std::string name;
        bool        isSigned;
        const int   gradeToSign; // required to sign it
        const int   gradeToExecute; // required to execute it
        const       std::string target;
        virtual void execute(const Bureaucrat& executor) const = 0;
    
    public:
        AForm(void);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute, std::string &target);

        //methods
        void        beSigned(const Bureaucrat &b);
        void        beExecuted(const Bureaucrat &b);
        // getters
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        bool        getIsSigned() const;
        std::string getName() const;
        std::string getTarget() const;
        

        class GradeTooHighException : public MyException {
            public:
            GradeTooHighException();
        };

        class GradeTooLowException : public MyException {
            public:
            GradeTooLowException();
        };

        class IsNotSignedException : public MyException {
            public:
            IsNotSignedException();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif

