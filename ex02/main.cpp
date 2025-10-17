#include "Bureaucrat.hpp"
#include "Form.hpp"

// Test de creación de formularios
void testFormCreation(const std::string& name, int gradeToSign, int gradeToExecute)
{
    std::cout << "\n🧾 Creando Formulario: " << name 
              << " (sign grade: " << gradeToSign 
              << ", execute grade: " << gradeToExecute << ")...\n";

    try
    {
        Form f(name, gradeToSign, gradeToExecute);
        std::cout << "✅ Creado correctamente: " << f << "\n";
    }
    catch (const MyException& e)
    {
        std::cerr << "❌ Error al crear Formulario: " << e << '\n';
    }
}

// Test de firma de formularios
void testFormSigning(Bureaucrat& b, Form& f)
{
    std::cout << "\n🖊️  Intentando que " << b.getName() 
              << " firme el formulario \"" << f.getName() << "\"...\n";

    b.signForm(f);

    std::cout << "📄 Estado actual del formulario: " 
              << (f.getIsSigned() ? "Firmado ✅" : "No firmado ❌") << "\n";
}

int main()
{
    std::cout << "🚀 Inicio de pruebas de Form\n";

    // Crear Bureaucrats de prueba
    Bureaucrat jefe("Jefe", 1);
    Bureaucrat empleado("Empleado", 100);

    // Crear formularios válidos e inválidos
    testFormCreation("Contrato", 50, 25);
    testFormCreation("Permiso", 1, 1);
    testFormCreation("Formulario ilegal bajo", 0, 10);
    testFormCreation("Formulario ilegal alto", 151, 150);

    // Instancia válida para pruebas
    Form contrato("Contrato", 50, 25);

    std::cout << "\n📌 Estado inicial:\n";
    std::cout << jefe << "\n" << empleado << "\n" << contrato << "\n";

    // Intento fallido: empleado no tiene rango suficiente
    testFormSigning(empleado, contrato);

    // Intento exitoso: jefe firma
    testFormSigning(jefe, contrato);

    std::cout << "\n🎉 Fin de pruebas\n";
    return 0;
}
