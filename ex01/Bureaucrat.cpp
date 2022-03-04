#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void) : _name("DEFAULT"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        this->_grade = src.getGrade();
    return (*this);
}


std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void        Bureaucrat::incrementGrade(void)
{
    if ((this->_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void        Bureaucrat::decrementGrade(void)
{
    if ((this->_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

void        Bureaucrat::signForm(Form &form)
{
    if (form.getSigned() == true)
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because it was signed already." << std::endl;
    else
    {
        try
        {
            form.beSigned(*this);
        }
        catch (std::exception &e)
        {
            std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
            return ;
        }
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
}


const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}


std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (o);
}
