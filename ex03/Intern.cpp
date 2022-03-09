#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern(void)
{}

Intern  &Intern::operator=(const Intern &src)
{
    if (this != &src)
    {
        (void )src;
    }
    return (*this);
}

static Form *createPresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

static Form *createRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static Form *createShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

Form    *Intern::makeForm(std::string form_name, std::string form_target)
{
    Form        *(*pt2Funcs[])( const std::string &target ) = { &createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm };
    std::string formTypes[] = { "presidential pardon", "robotomy request", "shrubbery creation" };

    for (int i = 0; i < 3; i++)
    {
        if (formTypes[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return ((*pt2Funcs[i])(form_target));
        }
    }
    std::cout << "Intern could not create form '" << form_name << "': No form like that exists." << std::endl;
    return (nullptr);
}
