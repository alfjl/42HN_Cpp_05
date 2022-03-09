#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n########## INTERNS ##########" << std::endl;
    Intern  number1;

    std::cout << "\n########## CREATE FORMS ##########" << std::endl;
    Form    *presidential;
    Form    *robotomy;
    Form    *shrubbery;
    Form    *rrf;

    presidential = number1.makeForm("presidential pardon", "Jimmy");
    robotomy = number1.makeForm("robotomy request", "Bender");
    shrubbery = number1.makeForm("shrubbery creation", "Woody");
    rrf = number1.makeForm("roqotomy rebuest", "Rendeb");
   
    std::cout << "\n########## BUREAUCRATS ##########" << std::endl;
    Bureaucrat  peter = Bureaucrat("Peter", 1);
    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;


    std::cout << "\n########## EXECUTE UNSIGNED & SIGNED FORMS ##########" << std::endl;
    if (presidential)
    {
        peter.executeForm(*presidential);
        peter.signForm(*presidential);
        peter.executeForm(*presidential);
        delete presidential;
    }
    if (robotomy)
    {
        peter.signForm(*robotomy);
        peter.executeForm(*robotomy);
        delete robotomy;
    }
    if (shrubbery)
    {
        peter.signForm(*shrubbery);
        peter.executeForm(*shrubbery);
        peter.executeForm(*shrubbery);
        delete shrubbery;
    }
    if (rrf)
    {
        peter.executeForm(*rrf);
        peter.signForm(*rrf);
        peter.executeForm(*rrf);
        delete rrf;
    }

    return (0);
}
