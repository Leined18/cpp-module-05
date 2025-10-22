#ifndef FORMFACTORY_HPP
# define FORMFACTORY_HPP
# include <iostream>
# include <string>
# include <cstring> // para strcmp
#include "AForm.hpp"

class FormFactory {
public:
    typedef AForm* (*Creator)(const std::string& target);

    FormFactory();
    ~FormFactory();
    FormFactory(const FormFactory &other);
    FormFactory &operator=(const FormFactory &other);
    static AForm* createForm(const char* name, const std::string& target);
    static bool registerForm(const char* name, Creator creator);

private:
    static const int _maxForms = 10;
    static const char *_formNames[_maxForms];
    static Creator _creators[_maxForms];
    static int _count;
};
#endif

