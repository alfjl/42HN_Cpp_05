#pragma once

#include <string>
#include "Form.hpp"

class   Intern
{
public:
    Intern(void);
    Intern(const Intern &other);
    ~Intern(void);

    Intern  &operator=(const Intern &src);

    Form    *makeForm(std::string form_name, std::string form_target);
};
