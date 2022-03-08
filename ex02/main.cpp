#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "\n########## BUREAUCRATS ##########" << std::endl;
    Bureaucrat  peter = Bureaucrat("Peter", 1);
    Bureaucrat  norbert = Bureaucrat("Norbert", 120);

    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;
    std::cout << norbert.getName() << std::endl;
    std::cout << norbert.getGrade() << std::endl;
   

    std::cout << "\n########## FORMS ##########" << std::endl;
    PresidentialPardonForm      x = PresidentialPardonForm("XXX");
    PresidentialPardonForm      y = PresidentialPardonForm("YYY");
    RobotomyRequestForm         r = RobotomyRequestForm("RRR");
    ShrubberyCreationForm       s1 = ShrubberyCreationForm("target1");
    ShrubberyCreationForm       s2 = ShrubberyCreationForm("target2");
    ShrubberyCreationForm       s3(s1);

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << "\n########## SIGNING X ##########" << std::endl;
    peter.signForm(x);
    norbert.signForm(x);
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << "\n########## EXECUTE UNSIGNED ##########" << std::endl;
    peter.executeForm(y);

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    
    std::cout << "\n########## Z(X) ##########" << std::endl;
    PresidentialPardonForm        z = PresidentialPardonForm(x);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    std::cout << "\n########## Z = Y ##########" << std::endl;
    z = y;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    std::cout << "\n########## SIGNING Y ##########" << std::endl;
    norbert.signForm(y);
    peter.signForm(y);
    
    std::cout << "\n########## EXECUTE SIGNED ##########" << std::endl;
    peter.executeForm(x);
    norbert.executeForm(y);
    peter.executeForm(y);
    peter.executeForm(z);
    
    std::cout << "\n########## EXECUTE SIGNED ROBOTOMY ##########" << std::endl;
    peter.signForm(r);
    peter.executeForm(r);

    std::cout << "\n########## EXECUTE UNSIGNED & SIGNED SHRUBBERY ##########" << std::endl;
    peter.executeForm(s1);
    peter.signForm(s1);
    norbert.signForm(s2);
    peter.executeForm(s1);
    norbert.executeForm(s2);
    peter.executeForm(s1);
    peter.executeForm(s1);
    norbert.executeForm(s1);
    norbert.executeForm(s2);
    peter.signForm(s3);
    norbert.executeForm(s3);
    peter.executeForm(s3);
    
    return (0);
}
