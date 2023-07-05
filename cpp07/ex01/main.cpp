/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:20:17 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 02:29:13 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Test con array di interi
    std::cout << "Stampa dei valori dell'array di interi:" << std::endl;
    iter(myArray, 5, print_value<int>);

    // Test con array di double
    double myDoubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "\nStampa dei valori dell'array di double:" << std::endl;
    iter(myDoubleArray, 5, print_value<double>);

    MyClass myObjects[] = {MyClass(1), MyClass(2), MyClass(3)};

    std::cout << "Stampa dei valori degli oggetti MyClass:" << std::endl;
    iter(myObjects, 3, print_value<MyClass>);

    return 0;
}