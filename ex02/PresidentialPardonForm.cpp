#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5)
                                                    , _target("DEFAULT")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
                                                    , _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : Form(other)
    , _target(other.getTarget())
{
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm    &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        this->Form::operator=(src);
        this->_target = src.getTarget();
    }
    return (*this);
}

std::string PresidentialPardonForm::getName(void) const
{
    return (this->Form::getName());
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

bool        PresidentialPardonForm::getSigned(void) const
{
    return (this->Form::getSigned());
}

int         PresidentialPardonForm::getSigningGrade(void) const
{
    return (this->Form::getSigningGrade());
}

int         PresidentialPardonForm::getExecutingGrade(void) const
{
    return (this->Form::getExecutingGrade());
}


void        PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->Form::getSigningGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    else
        this->Form::beSigned(bureaucrat);
}

void        PresidentialPardonForm::execute(const Bureaucrat &executor) const
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
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char  *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char  *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}

const char  *PresidentialPardonForm::NotSignedException::what() const throw()
{
    return ("Exception: PresidentialPardonForm NOT signed");
}

const char  *PresidentialPardonForm::ExecutingGradeTooLowException::what() const throw()
{
    return ("Exception: Bureaucrats grade too low to execute this form");
}

