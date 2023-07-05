/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:41:37 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/01 07:39:56 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
    this->name = new std::string(name);
    setGrade(grade);
    std::cout << "Bur created\n";
}

Bureaucrat::~Bureaucrat()
{
    delete name;
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

    this->name = new std::string(*src.name);
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
    if (grade < 1)
    {
        delete name;
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        delete name;
        throw GradeTooLowException();
    }
    else
    {
        this->grade = grade;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
    {
        throw GradeTooHighException();
    }
    else
    {
        this->grade--;
    }
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
    {
        throw GradeTooLowException();
    }
    else
    {
        this->grade++;
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high\n";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
    os << bur.getName() << ", bur grade " << bur.getGrade() << ".";
    return os;
}
