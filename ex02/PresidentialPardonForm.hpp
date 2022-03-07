#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class   Bureaucrat;

class   PresidentialPardonForm : public Form
{
private:
    std::string _target;

    PresidentialPardonForm(void);

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm    &operator=(const PresidentialPardonForm &src);

    std::string getName(void) const;
    std::string getTarget(void) const;
    bool        getSigned(void) const;
    int         getSigningGrade(void) const;
    int         getExecutingGrade(void) const;

    void        beSigned(const Bureaucrat &bureaucrat);
    void        execute(const Bureaucrat &executor) const;

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
