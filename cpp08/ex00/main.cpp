/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:35:21 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 05:40:57 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        // Cerca il valore 3 nel vettore
        std::vector<int>::iterator vecIt = easyfind(vec, 123);
        if (vecIt != vec.end()) 
        {
            std::cout << "Element found in vector: " << *vecIt << std::endl;
        } 
        else 
        {
            std::cout << "Element not found in vector." << std::endl;
        }
    } 
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what();
    }

    return 0;
}