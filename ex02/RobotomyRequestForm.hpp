#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class   Bureaucrat;

class   RobotomyRequestForm : public Form
{
private:
    std::string _target;

    RobotomyRequestForm(void);

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm    &operator=(const RobotomyRequestForm &src);

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
