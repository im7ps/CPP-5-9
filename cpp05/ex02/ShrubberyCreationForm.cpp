/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:56:51 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 21:56:52 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("Shrubbery Request Form", 145, 137)
{
    this->target = target;
    std::cout << "Shrubbery Form created\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Form deleted\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cpy)
{
    *this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
    if (this == &src)
        return *this;

    this->target = src.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
    try
    {
        if (this->isSigned() && executor.getGrade() <= this->getGradeToExc())
        {
            std::ofstream file( this->target + "_shrubbery" );
            file << "                      ___" << std::endl;
            file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
            file << "             ,-'          __,,-- \\" << std::endl;
            file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
            file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
            file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
            file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
            file << "     (     ,-'                  `." << std::endl;
            file << "      `._,'     _   _             ;" << std::endl;
            file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
            file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
            file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
            file << "                \"Hb HH dF" << std::endl;
            file << "                 \"HbHHdF" << std::endl;
            file << "                  |HHHF" << std::endl;
            file << "                  |HHH|" << std::endl;
            file << "                  |HHH|" << std::endl;
            file << "                  |HHH|" << std::endl;
            file << "                  |HHH|" << std::endl;
            file << "                  dHHHb" << std::endl;
            file << "                .dFd|bHb.               o" << std::endl;
            file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
            file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
            file << "##########################################" << std::endl;
            file.close();   
        }
        else
        {
            throw GradeTooLowException();
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}