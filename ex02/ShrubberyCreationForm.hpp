#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _signingGrade;
    const int           _executingGrade;
    
    Form(void);
public:
    Form(std::string name, int signingGrade, int executingGrade);
    Form(const Form &other);
    ~Form(void);

    Form    &operator=(const Form &src);

    std::string   getName(void) const;
    bool                getSigned(void) const;
    int           getSigningGrade(void) const;
    int           getExecutingGrade(void) const;

    void                beSigned(const Bureaucrat &bureaucrat);

    class   GradeTooLowException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class   GradeTooHighException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };
    
    class   NotSignedException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class   ExecutingGradeTooLowException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };
};

std::ostream    &operator<<(std::ostream &o, const Form &f);
