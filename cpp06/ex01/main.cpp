/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:32:37 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 23:32:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main() {
    Data* dataexample = new Data("canederli");
    std::uintptr_t intexample = 0;

    intexample = dataexample->serialize(dataexample);

    Data* deserializedData = dataexample->deserialize(intexample);

    Data test = *deserializedData;

    Data test2(*dataexample);

    std::cout << dataexample << std::endl;
    std::cout << deserializedData << std::endl;
    std::cout << &test << std::endl;
    std::cout << &test2 << std::endl;

    std::cout << dataexample->getString() << std::endl;
    std::cout << deserializedData->getString() << std::endl;
    std::cout << test.getString() << std::endl;
    std::cout << test2.getString() << std::endl;

    delete dataexample;

    return 0;
}
