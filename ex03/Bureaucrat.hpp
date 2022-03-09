#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class   Form;

class   Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;
    Bureaucrat(void);

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat  &operator=(const Bureaucrat &src);

    std::string getName(void) const;
    int         getGrade(void) const;
    void        incrementGrade(void);
    void        decrementGrade(void);
    void        signForm(Form &form);
    void        executeForm(Form const &form);

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
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);
