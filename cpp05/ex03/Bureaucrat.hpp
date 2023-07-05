/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:35:03 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 09:20:14 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string*      name;
        int                     grade;
    public:
        std::string const&  getName() const;
        int                 getGrade() const;
        void                setGrade(int grade);
         
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const& cpy);
        Bureaucrat& operator=(Bureaucrat const& src);

        void                incrementGrade();
        void                decrementGrade();

        void                signForm(const AForm& form) const;

        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        void                signForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);

#endif