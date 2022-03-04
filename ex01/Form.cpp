#include "Form.hpp"

Form::Form(void) : _name("DEFAULT"), _signed(false), _signingGrade(150), _executingGrade(150)
{}

Form::Form(std::string name, int signingGrade, int executingGrade)
    : _name(name), _signed(false), _signingGrade(signingGrade), _executingGrade(executingGrade)
{

    if (signingGrade < 1 || executingGrade < 1)
        throw Form::GradeTooHighException();
    else if (signingGrade > 150 || executingGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other.getName()), _signingGrade(other.getSigningGrade()), _executingGrade(other.getExecutingGrade())
{
    *this = other;
}

Form::~Form(void)
{}

Form    &Form::operator=(const Form &src)
{
    if (this != &src)
        this->_signed = src.getSigned();
    return (*this);
}

std::string   Form::getName(void) const
{
    return (this->_name);
}

bool                Form::getSigned(void) const
{
    return (this->_signed);
}

int           Form::getSigningGrade(void) const
{
    return (this->_signingGrade);
}

int           Form::getExecutingGrade(void) const
{
    return (this->_executingGrade);
}


void                Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signingGrade)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

const char          *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char          *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}

std::ostream        &operator<<(std::ostream &o, const Form &f)
{
    o << " --- Form: " << f.getName() << " --- "
        << "\nsigned: " << f.getSigned()
        << "\nsigning grade: " << f.getSigningGrade()
        << "\nexecuting grade: " << f.getExecutingGrade()
        << std::endl;
    return (o);
}
