/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:38:41 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 07:20:27 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private:
        const std::string*  name;
        bool                sign;
        const int*          grade_to_sign;
        const int*          grade_to_exc;
    public:
        Form(const std::string&  name, const int& grade_to_sign, const int& grade_to_exc);
        ~Form();
        Form(Form const& cpy);
        Form& operator=(Form const& src);

        const std::string&  getName() const;
        bool                isSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExc() const;

        int                setGrades(int grade_to_sign, int grade_to_exc);

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

    void    beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream&, const Form& ref);

#endif
