/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:23:59 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 17:42:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        Converter conv(argv[1]);
    }
    else 
    {
        std::cout << "Error !" << std::endl;
    }
}