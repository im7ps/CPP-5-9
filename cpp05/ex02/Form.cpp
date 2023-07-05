/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:56:34 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 21:56:35 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

AForm::AForm()
{
    ;
}

AForm::AForm(const std::string& name, const int& grade_to_sign, const int& grade_to_exc)
{
    try
    {
        int grade;

        this->name = new std::string(name);
        this->sign = false;
        grade = setGrades(grade_to_sign, grade_to_exc);
        if (grade == 1)
        {
            throw GradeTooHighException();
        }
        else if (grade == 2)
        {
            throw GradeTooLowException();
        }
        std::cout << "Form created\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw;
    }
    
}

AForm::AForm(AForm const& cpy)
{
    *this = cpy;
}

AForm& AForm::operator=(AForm const& src)
{
    if (this == &src)
        return *this;

    if (this->name != nullptr)
    {
        delete (this->name);
    }
    this->name = new std::string(*src.name);
    this->sign = src.sign;
    this->grade_to_sign = new int(*src.grade_to_sign);
    this->grade_to_exc = new int(*src.grade_to_exc);

    return *this;
}

AForm::~AForm()
{
    delete name;
    delete grade_to_sign;
    delete grade_to_exc;
    std::cout << "Form deleted\n";
}

const std::string& AForm::getName() const
{
    return *(this->name);
}

bool AForm::isSigned() const
{
    return this->sign;
}

int AForm::getGradeToSign() const
{
    return *(this->grade_to_sign);
}

int AForm::getGradeToExc() const
{
    return *(this->grade_to_exc);
}

int AForm::setGrades(int grade_to_sign, int grade_to_exc)
{

        if (grade_to_sign < 1 || grade_to_exc < 1)
        {
            return 1;
        }
        else if (grade_to_sign > 150 || grade_to_exc > 150)
        {
            return 2;
        }
        else
        {
            this->grade_to_sign = new int(grade_to_sign);
            this->grade_to_exc = new int(grade_to_exc);
        }
        return 0;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low\n";
}

void AForm::beSigned(const Bureaucrat& bur)
{
    try
    {
        if (bur.getGrade() <= this->getGradeToSign())
        {
            this->sign = true;
        }
        else
        {
            throw GradeTooLowException();
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what();
        throw;
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << " | form status " << form.isSigned() << " | form grade to sign " << form.getGradeToSign() << " | form grade to excecute " << form.getGradeToExc() << "\n";
    return os;
}
