/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:41:37 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 11:13:06 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    ;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
    this->name = &name;
    setGrade(grade);
    std::cout << "Bur created\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bur deleted\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const& cpy)
{
    *this = cpy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
    if (this == &src)
        return *this;

    this->name = &(*src.name);
    this->grade = src.grade;
    return *this;
}

std::string const& Bureaucrat::getName() const
{
    return *(this->name);
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade < 1)
        {
            this->grade = -276447231;
            throw Bureaucrat::GradeTooHighException();
        }
        else if (grade > 150)
        {
            this->grade = 276447232;
            throw Bureaucrat::GradeTooLowException();
        }
        else
        {
            this->grade = grade;
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
    catch(const GradeTooHighException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (this->grade <= 1)
        {
            throw Bureaucrat::GradeTooHighException();
        }
        else
        {
            this->grade--;
        }
    }
    catch(const GradeTooHighException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
    
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (this->grade >= 150)
        {
            throw Bureaucrat::GradeTooLowException();
        }
        else
        {
            this->grade++;
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bur grade is too low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bur grade is too high\n");
}

void    Bureaucrat::signForm(const AForm& form)
{
    try
    {
        if (form.isSigned())
        {
            std::cout << this->getName() << " signed " << form.getName() << "\n";
        }
        else
        {
            std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
            throw GradeTooLowException();
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
    os << bur.getName() << " | bur grade " << bur.getGrade() << ".\n";
    return os;
}
