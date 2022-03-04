#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  peter = Bureaucrat("Peter", 150);
    Bureaucrat  *maria = new Bureaucrat("Maria", 1);
    //Bureaucrat  *norbert = new Bureaucrat(*maria); // works
    Bureaucrat  *norbert = new Bureaucrat("Norbert", 123);

    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;
    std::cout << maria->getName() << std::endl;
    std::cout << maria->getGrade() << std::endl;
    std::cout << norbert->getName() << std::endl;
    std::cout << norbert->getGrade() << std::endl;
    
    std::cout << "\n########## NORBERT = MARIA ##########" << std::endl;
    *(norbert) = *(maria);
    std::cout << norbert->getName() << std::endl;
    std::cout << norbert->getGrade() << std::endl;

    std::cout << "\n########## TRY CORRECT ##########" << std::endl;
    try
    {
        peter.incrementGrade();
        maria->decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << " caught!" << std::endl;
        delete (maria);
        delete (norbert);
        return (1);
    }
    
    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;
    std::cout << maria->getName() << std::endl;
    std::cout << maria->getGrade() << std::endl;

    std::cout << "\n########## TRY INCORRECT ##########" << std::endl;
    try
    {
        // check between ..TooHigh.. & ..TOOLOW..
        //peter.decrementGrade();
        maria->incrementGrade();
        //peter.decrementGrade();
        maria->incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << " caught!" << std::endl;
        delete (maria);
        delete (norbert);
        return (1);
    }

    std::cout << peter.getName() << std::endl;
    std::cout << peter.getGrade() << std::endl;
    std::cout << maria->getName() << std::endl;
    std::cout << maria->getGrade() << std::endl;
    
    delete (maria);
    delete (norbert);

    return (0);
}
