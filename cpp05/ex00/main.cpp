/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:56:21 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 21:56:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try
    {
        Bureaucrat b1("John Doe", 2);
        std::cout << b1 << std::endl;

        Bureaucrat b2 = b1;
        std::cout << "B2 name: " << b2.getName() << "\n";

        // std::cout << "before promotion\nBur grade: " << b1.getGrade() << std::endl;
        b1.incrementGrade();
        // std::cout << "after promotion\nBur grade: " << b1.getGrade() << std::endl;

        // std::cout << "before too much promotion\nBur grade: " << b1.getGrade() << std::endl;
        b1.incrementGrade();
        // std::cout << "after too much promotion\nBur grade: " << b1.getGrade() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Promotion exception: " << e.what();
    }

    try
    {
        Bureaucrat b2("Jake Lafuria", 200);
        std::cout << b2 << std::endl;

        Bureaucrat b3("Don Joe", -10);
        std::cout << b3 << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cout << "Construction exception: " << e.what();
    }
    return 0;
}