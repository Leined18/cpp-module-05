#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ----------------------------
// Funciones auxiliares
// ----------------------------

void trySign(Bureaucrat& b, AForm& f)
{
    std::cout << "\n🖋️ " << b.getName() << " intenta firmar " << f.getName() << "...\n";
    try {
        b.signForm(f);
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }
}

void tryExecute(Bureaucrat& b, AForm& f)
{
    std::cout << "\n⚙️ " << b.getName() << " intenta ejecutar " << f.getName() << "...\n";
    try {
        b.executeForm(f);
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }
}

void runTests(Bureaucrat& b, AForm* forms[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        AForm* f = forms[i];
        if (!f) continue;

        std::cout << "\n📄 Formulario:\n" << *f << std::endl;
        trySign(b, *f);
        tryExecute(b, *f);
    }
}

// ----------------------------
// Programa principal
// ----------------------------


int main()
{
    std::srand(std::time(NULL)); // Semilla para rand()

    std::cout << "🚀 Inicio de pruebas\n";

    // Crear burócratas
    Bureaucrat jefe("Jefe", 1);
    Bureaucrat empleado("Empleado", 110);

    // Crear Intern y usar makeForm
    Intern intern;
    AForm* forms[3];
    forms[0] = intern.makeForm("shrubbery creation", "Jardin");
    forms[1] = intern.makeForm("robotomy request", "Robot-X");
    forms[2] = intern.makeForm("presidential pardon", "Inocente");

    std::cout << "\n🔍 Pruebas con empleado (rango insuficiente)\n";
    runTests(empleado, forms, 3);

    std::cout << "\n✅ Pruebas con jefe (rango máximo)\n";
    runTests(jefe, forms, 3);

    // Liberar memoria (evitar leaks)
    for (int i = 0; i < 3; ++i)
        delete forms[i];

    std::cout << "\n🎉 Fin de pruebas\n";
    return 0;
}
