#include "Bureaucrat.hpp"

int main(int argc, char const *argv[])
{
    if (!argc && !argv)
        return 0;
    Bureaucrat b1("Marta", 1);
    Bureaucrat b2("Luis", 7);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    testDecrement(b1, 149);
    testIncrement(b2, 6);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    testDecrement(b1, 1);
    testIncrement(b2, 1);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    
    return 0;
}
