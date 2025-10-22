#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::GradeTooHighException::GradeTooHighException() : MyException("Grade too high!") {}
Bureaucrat::GradeTooLowException::GradeTooLowException() : MyException("Grade too low!") {}

// methods

void Bureaucrat::decrementGrade(int n)
{
    if ((grade + n) > 150)
        throw GradeTooLowException();
    this->grade += n;

}

void Bureaucrat::incrementGrade(int n)
{
    if ((grade - n) < 1)
        throw GradeTooHighException();
    this->grade -= n;
}

void Bureaucrat::signForm(AForm &f)
{
    try{
        f.beSigned(*this);
        std::cout << *this << " signed " << f.getName() << std::endl;
    }
    catch (MyException &e){
        std::cout << *this << " couldn’t sign " << f.getName() << " because " << e << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &f)
{
    try{
        f.beExecuted(*this);
        std::cout << *this << " executed " << f.getName() << std::endl;
    }
    catch (MyException &e){
        std::cout << *this << " couldn’t execute " << f.getName() << " because " << e << std::endl;
    }
}

// getters

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

// Default constructor
Bureaucrat::Bureaucrat(void) : name("unknown"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name = other.name;
        grade = other.grade;
    }
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void) {}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", Bureaucrat grade " << b.getGrade(); 
    return os;
}


