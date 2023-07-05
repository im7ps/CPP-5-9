/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:38:11 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 07:40:44 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

    try
    {
        Form formoso("Formoso", 45, 13);
        std::cout << formoso;
        Form famoso = formoso;
        std::cout << famoso;

        Bureaucrat b1 = Bureaucrat("Fungia", 1);
        std::cout << b1;
        Bureaucrat b2 = b1;

        b2.decrementGrade();
        b2.decrementGrade();
        std::cout << b2;

        formoso.beSigned(b2);

        b1.signForm(formoso);
        b1.signForm(famoso);
    
        Bureaucrat b3 = Bureaucrat("Fungia", 210);
        std::cout << b3;

    }
    catch (const std::exception& e)
    {
        return 1;
    }
    return (0);
}