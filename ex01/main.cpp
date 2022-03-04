#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n########## BUREAUCRATS ##########" << std::endl;
    Bureaucrat  peter = Bureaucrat("Peter", 121);
    Bureaucrat  norbert = Bureaucrat("Norbert", 120);
    Bureaucrat  *maria = new Bureaucrat("Maria", 119);

    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;
    std::cout << maria->getName() << std::endl;
    std::cout << maria->getGrade() << std::endl;
   

    std::cout << "\n########## FORMS ##########" << std::endl;
    Form        x = Form("XP9/14-5", 120, 121);
    Form        y = Form("YQ24/17-7", 99, 99);
    try
    {
        //Form        y = Form("YQ24/17-7", 0, 121);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << "\n########## SIGNING X ##########" << std::endl;
    peter.signForm(x);
    norbert.signForm(x);
    maria->signForm(x);
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << "\n########## Z(X) ##########" << std::endl;
    Form        z = Form(x);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    std::cout << "\n########## Z = Y ##########" << std::endl;
    z = y;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    std::cout << "\n########## DESTRUCTORS ##########" << std::endl;
    delete (maria);

    return (0);
}
