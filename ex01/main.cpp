#include "Bureaucrat.hpp"
#include "Form.hpp"

// Utilidad para testear incrementos
void testIncrement(Bureaucrat &b, int n)
{
    std::cout << "\n🔼 Intentando incrementar el grado de " << b.getName() << " en " << n << "...\n";
    try
    {
        b.incrementGrade(n);
        std::cout << "✅ Nuevo grado: " << b.getGrade() << "\n";
    }
    catch(const MyException& e)
    {
        std::cerr << "❌ Excepción atrapada: " << e << '\n';
    }
}

// Utilidad para testear decrementos
void testDecrement(Bureaucrat &b, int n)
{
    std::cout << "\n🔽 Intentando decrementar el grado de " << b.getName() << " en " << n << "...\n";
    try
    {
        b.decrementGrade(n);
        std::cout << "✅ Nuevo grado: " << b.getGrade() << "\n";
    }
    catch(const MyException& e)
    {
        std::cerr << "❌ Excepción atrapada: " << e << '\n';
    }
}

// Test para creación de Bureaucrats
void testCreation(const std::string& name, int grade)
{
    std::cout << "\n🧪 Creando Bureaucrat: " << name << " con grado " << grade << "...\n";
    try
    {
        Bureaucrat b(name, grade);
        std::cout << "✅ Creado correctamente: " << b << '\n';
    }
    catch (const MyException& e)
    {
        std::cerr << "❌ Error al crear Bureaucrat: " << e << '\n';
    }
}

int main()
{
    std::cout << "🚀 Inicio de pruebas de Bureaucrat\n";

    // Pruebas de creación
    testCreation("Marta", 1);
    testCreation("Luis", 7);
    testCreation("Nivel bajo", 151);
    testCreation("Nivel alto", 0);

    // Instancias válidas
    Bureaucrat b1("Marta", 1);
    Bureaucrat b2("Luis", 7);

    std::cout << "\n📌 Estado inicial:\n";
    std::cout << b1 << "\n";
    std::cout << b2 << "\n";

    // Pruebas normales
    testDecrement(b1, 1);    // Marta: de 1 a 2
    testIncrement(b2, 3);    // Luis: de 7 a 4

    // Pruebas límite
    testDecrement(b1, 148);  // Marta: de 2 a 150
    testIncrement(b2, 3);    // Luis: de 4 a 1

    // Excepciones esperadas
    testDecrement(b1, 1);    // Marta ya está en 150
    testIncrement(b2, 1);    // Luis ya está en 1

    std::cout << "\n📌 Estado final:\n";
    std::cout << b1 << "\n";
    std::cout << b2 << "\n";

    std::cout << "\n🎉!! Form pruebas\n";
    Form f("form1", 3, 2);

    f.beSigned(b2);
    std::cout << f << std::endl;

    std::cout << "\n🎉 Fin de pruebas\n";
    return 0;
}
