#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Exceptions
AForm::GradeTooHighException::GradeTooHighException() : MyException("Grade too high!") {}
AForm::GradeTooLowException::GradeTooLowException() : MyException("Grade too low!") {}
AForm::IsNotSignedException::IsNotSignedException() : MyException("Form Not Signed!") {}

// methods

void AForm::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

void AForm::beExecuted(const Bureaucrat &b) 
{
    if (b.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
    if (!this->getIsSigned())
        throw IsNotSignedException();
    this->execute(b);
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

std::string AForm::getTarget() const
{
    return (this->target);
}

// Default constructor
AForm::AForm(void): gradeToSign(0),gradeToExecute(0)
{
    throw MyException("Cannot construct an empty Form");
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, std::string &target)
    : name(name), isSigned(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target)
{
    // Aquí puedes lanzar excepciones si los valores son inválidos
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target)
{
    (void) other;
    return ;
}

AForm &AForm::operator=(const AForm &other)
{
    (void)other;
    return (*this);
}

// Destructor
AForm::~AForm(void){}


// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << BOLD << CYAN << "📄 Form: " << RESET << "\"" << f.getName() << "\"\n"
       << "   " << YELLOW << "• Signed: " << RESET << (f.getIsSigned() ? GREEN "yes" RESET : RED "no" RESET) << "\n"
       << "   " << YELLOW << "• Grade to Sign: " << RESET << f.getGradeToSign() << "\n"
       << "   " << YELLOW << "• Grade to Execute: " << RESET << f.getGradeToExecute() << "\n";
    return os;
}