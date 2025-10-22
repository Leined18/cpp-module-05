#include "RobotomyRequestForm.hpp"

// To Complete
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    (void)executor;
    std::cout << YELLOW << "Brrrr... drilling noises..." << RESET << std::endl;

    if (rand() % 2 == 0)  // 50% chance
        std::cout << GREEN << target << " has been robotomized successfully." << RESET << std::endl;
    else
        std::cout << RED << "Robotomy failed on " << target << "." << RESET << std::endl;
}

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) :AForm()
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm",  72, 45, target)
{
    return ;
}

AForm* RobotomyRequestForm::create(const std::string& target) {
    return new RobotomyRequestForm(target);
}

// Auto-registro al cargar la clase
bool RobotomyRequestForm::_registered =
FormFactory::registerForm("robotomy request", &RobotomyRequestForm::create);


// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
AForm(other)
{
    (void) other;
    return ;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void) other;
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f)
{
    os << static_cast<const AForm&>(f) // usa el bonito de AForm
       << "\n   " << MAGENTA << "• Target: " << RESET << f.getTarget();
    return os;
}

