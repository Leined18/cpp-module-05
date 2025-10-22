#include "ShrubberyCreationForm.hpp"

// To Complete
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    (void)executor;
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw std::ios_base::failure("Error al abrir el archivo");
    file << "     🌲\n"
            "    🌲🌲\n"
            "   🌲🌲🌲\n"
            " 🌲🌲🌲🌲🌲\n"
            "    ||||\n";
    file.close();
}

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void):AForm()
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm",  145, 137, target)
{
    return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void){}
// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f)
{
    os << static_cast<const AForm&>(f) // usa el bonito de AForm
       << "\n   " << MAGENTA << "• Target: " << RESET << f.getTarget();
    return os;
}
