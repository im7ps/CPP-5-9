/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:38:41 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 11:22:49 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string*  name;
        bool                sign;
        const int*          grade_to_sign;
        const int*          grade_to_exc;
    public:
        AForm();
        AForm(const std::string& name, const int& grade_to_sign, const int& grade_to_exc);
        AForm(AForm const& cpy);
        AForm& operator=(AForm const& src);
        virtual ~AForm();

        const std::string&  getName() const;
        bool                isSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExc() const;

        int                setGrades(int grade_to_sign, int grade_to_exc);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw(); 
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    void    beSigned(const Bureaucrat& bur);

    virtual void execute(Bureaucrat const& executor) = 0;
    
};

std::ostream& operator<<(std::ostream&, const AForm& ref);

#endif
