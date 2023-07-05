/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:56:53 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 21:56:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_FORM_HPP
# define SHRUBBERY_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& ShrubberyForm);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& ShrubberyForm);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor);
};

#endif