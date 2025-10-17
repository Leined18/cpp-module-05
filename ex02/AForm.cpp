#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Exceptions
AForm::GradeTooHighException::GradeTooHighException() : MyException("Grade too high!") {}
AForm::GradeTooLowException::GradeTooLowException() : MyException("Grade too low!") {}

// methods

void AForm::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

//getters
int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

std::string AForm::getName() const
{
    return (this->name);
}

// Default constructor
AForm::AForm(void) : name(""), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
    throw MyException("Cannot construct an empty AForm");
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    // Aquí puedes lanzar excepciones si los valores son inválidos
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
AForm::~AForm(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}



// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm \"" << f.getName()
       << "\", (signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute() << ")";
    return os;
}
