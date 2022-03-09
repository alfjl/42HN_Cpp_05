#include <sys/time.h>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45)
                                                    , _target("DEFAULT")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
                                                    , _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other)
    , _target(other.getTarget())
{
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm    &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
    {
        this->Form::operator=(src);
        this->_target = src.getTarget();
    }
    return (*this);
}

std::string RobotomyRequestForm::getName(void) const
{
    return (this->Form::getName());
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

bool        RobotomyRequestForm::getSigned(void) const
{
    return (this->Form::getSigned());
}

int         RobotomyRequestForm::getSigningGrade(void) const
{
    return (this->Form::getSigningGrade());
}

int         RobotomyRequestForm::getExecutingGrade(void) const
{
    return (this->Form::getExecutingGrade());
}


void        RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->Form::getSigningGrade())
        throw RobotomyRequestForm::GradeTooLowException();
    else
        this->Form::beSigned(bureaucrat);
}

void        RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    int             robotomizedYesOrNo;

    srand(time(0));
    try
    {
        this->Form::execute(executor);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw e;
    }
    std::cout << "DRRRRRRRRRRRRRRRRRRRRRRrrrrrrrrrrrrrrrrrr................" << std::endl;
    robotomizedYesOrNo = std::rand() % 2;
    if (robotomizedYesOrNo == 1)
        std::cout << this->_target << " has been robotomized." << std::endl;
    else
        std::cout << this->_target << " failed to be robotomized." << std::endl;
}

const char  *RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char  *RobotomyRequestForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}

const char  *RobotomyRequestForm::NotSignedException::what() const throw()
{
    return ("Exception: RobotomyRequestForm NOT signed");
}

const char  *RobotomyRequestForm::ExecutingGradeTooLowException::what() const throw()
{
    return ("Exception: Bureaucrats grade too low to execute this form");
}

