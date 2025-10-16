#include "Bureaucrat.hpp"

void testIncrement(Bureaucrat &b, int n)
{
    try
    {
        b.incrementGrade(n);
        std::cout << "Nuevo grado de " << b.getName() << ": " << b.getGrade() << '\n';
    }
    catch(const MyException& e)
    {
        std::cerr << e << '\n';
    }
}

void testDecrement(Bureaucrat &b, int n)
{
    try
    {
        b.decrementGrade(n);
        std::cout << "Nuevo grado de " << b.getName() << ": " << b.getGrade() << '\n';
    }
    catch(const MyException& e)
    {
        std::cerr << e << '\n';
    }
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw MyException("Error: cannot decrement beyond 150");
    this->grade += 1;

}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw MyException("Error: cannot increment beyond 1");
    this->grade -= 1;
}

void Bureaucrat::decrementGrade(int n)
{
    if (grade >= 150)
        throw MyException("Error: cannot decrement beyond 150");
    if ((grade + n) > 150)
        throw MyException("Error: cannot decrement beyond 150 + n");
    this->grade += n;

}

void Bureaucrat::incrementGrade(int n)
{
    if (grade <= 1)
        throw MyException("Error: cannot increment beyond 1");
    if ((grade - n) < 1)
        throw MyException("Error: cannot increment beyond 1 - n");
    this->grade -= n;
}



// Default constructor
Bureaucrat::Bureaucrat(void) : name("unknown"), grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    return ;
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", Bureaucrat grade " << b.getGrade(); 
    return os;
}


