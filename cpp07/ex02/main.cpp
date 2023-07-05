/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:34:13 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 04:03:34 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
    try
    {
        // Creazione di un oggetto Array di interi
        Array<int> intArray(5);

        // Inizializzazione degli elementi
        for (size_t i = 0; i < intArray.getSize(); i++) {
            intArray[i] = i + 1;
        }

        // Stampa degli elementi
        for (size_t i = 0; i < intArray.getSize(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Creazione di un oggetto Array di double
        Array<double> doubleArray(3);

        // Inizializzazione degli elementi
        for (size_t i = 0; i < doubleArray.getSize(); i++) {
            doubleArray[i + 6] = (i + 1) * 0.5;
        }

        // Stampa degli elementi
        for (size_t i = 0; i < doubleArray.getSize(); i++) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
    
        int *a = new int();
        std::cout << *a << std::endl; 
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Segmentation Fault\n";
    }
    return 0;
}