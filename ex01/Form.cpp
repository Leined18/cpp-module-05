#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exceptions
Form::GradeTooHighException::GradeTooHighException() : MyException("Grade too high!") {}
Form::GradeTooLowException::GradeTooLowException() : MyException("Grade too low!") {}

// methods

void Form::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

//getters
int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

std::string Form::getName() const
{
    return (this->name);
}

// Default constructor
Form::Form(void) : name(""), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
    throw MyException("Cannot construct an empty Form");
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
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
Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Form::~Form(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << BOLD << CYAN << "📄 Form: " << RESET << "\"" << f.getName() << "\"\n"
       << "   " << YELLOW << "• Signed: " << RESET << (f.getIsSigned() ? GREEN "yes" RESET : RED "no" RESET) << "\n"
       << "   " << YELLOW << "• Grade to Sign: " << RESET << f.getGradeToSign() << "\n"
       << "   " << YELLOW << "• Grade to Execute: " << RESET << f.getGradeToExecute() << "\n";
    return os;
}
