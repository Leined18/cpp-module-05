#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Intentar firmar un formulario
void trySign(Bureaucrat& b, AForm& f)
{
    std::cout << "\n🖋️ " << b.getName() << " intenta firmar " << f.getName() << "...\n";
    try {
        b.signForm(f);
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }
}

// Intentar ejecutar un formulario
void tryExecute(Bureaucrat& b, AForm& f)
{
    std::cout << "\n⚙️ " << b.getName() << " intenta ejecutar " << f.getName() << "...\n";
    try {
        b.executeForm(f);
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }
}

// Ejecutar pruebas con un burócrata y lista de formularios
void runTests(Bureaucrat& b, std::vector<AForm*>& forms)
{
    for (size_t i = 0; i < forms.size(); ++i)
    {
        AForm* f = forms[i];
        std::cout << "\n📄 Formulario:\n" << *f << std::endl;
        trySign(b, *f);
        tryExecute(b, *f);
    }
}

int main()
{
    std::srand(std::time(NULL)); // Inicializar rand()

    std::cout << "🚀 Inicio de pruebas\n";

    // Crear burócratas
    Bureaucrat jefe("Jefe", 1);
    Bureaucrat empleado("Empleado", 110);

    // Crear formularios concretos
    ShrubberyCreationForm shrub("Jardin");
    RobotomyRequestForm robo("Robot-X");
    PresidentialPardonForm pardon("Inocente");

    // Lista de formularios
    std::vector<AForm*> forms;
    forms.push_back(&shrub);
    forms.push_back(&robo);
    forms.push_back(&pardon);

    std::cout << "\n🔍 Pruebas con empleado (rango insuficiente)\n";
    runTests(empleado, forms);

    std::cout << "\n✅ Pruebas con jefe (rango máximo)\n";
    runTests(jefe, forms);

    std::cout << "\n🎉 Fin de pruebas\n";
    return 0;
}
