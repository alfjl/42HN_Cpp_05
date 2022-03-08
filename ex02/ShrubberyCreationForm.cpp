#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137)
                                                    , _target("DEFAULT")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
                                                    , _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other)
    , _target(other.getTarget())
{
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        this->Form::operator=(src);
        this->_target = src.getTarget();
    }
    return (*this);
}

std::string ShrubberyCreationForm::getName(void) const
{
    return (this->Form::getName());
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

bool        ShrubberyCreationForm::getSigned(void) const
{
    return (this->Form::getSigned());
}

int         ShrubberyCreationForm::getSigningGrade(void) const
{
    return (this->Form::getSigningGrade());
}

int         ShrubberyCreationForm::getExecutingGrade(void) const
{
    return (this->Form::getExecutingGrade());
}


void        ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->Form::getSigningGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    else
        this->Form::beSigned(bureaucrat);
}

void        ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    try
    {
        this->Form::execute(executor);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw e;
    }
    std::ofstream   outfile(this->_target + "_shrubbery", std::ios_base::out | std::ios_base::app);
    if (!outfile)
    {
        std::cout << "Error: can't open or create outfile " << this->_target + "_shrubbery" << std::endl;
        return ;
    }
    else
    {
        outfile
        << "          &&& &&  & &&\n"
        << "      && &\\/&\\|& ()|/ @, &&\n"
        << "      &\\/(/&/&||/& /_/)_&/_&\n"
        << "   &() &\\/&|()|/&\\/ '%\\ & ()\n"
        << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        << "&&   && & &| &| /& & % ()& /&&\n"
        << " ()&_---()&\\&\\|&&-&&--%---()~\n"
        << "     &&     \\|||\n"
        << "             |||\n"
        << "             |||\n"
        << "             |||\n"
        << "       , -=-~  .-^- _\n"
        << "ejm97         `" << std::endl;
    }
    outfile.close();
}

const char  *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char  *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}

const char  *ShrubberyCreationForm::NotSignedException::what() const throw()
{
    return ("Exception: ShrubberyCreationForm NOT signed");
}

const char  *ShrubberyCreationForm::ExecutingGradeTooLowException::what() const throw()
{
    return ("Exception: Bureaucrats grade too low to execute this form");
}

