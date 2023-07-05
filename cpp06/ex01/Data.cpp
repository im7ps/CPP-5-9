/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:32:31 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 23:32:32 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
    std::cout << "Data created\n";
}

Data::Data(std::string const& str) : str(str)
{
    ;
}

Data::Data(Data const& cpy)
{
    *this = cpy;
}

Data& Data::operator=(Data const& src)
{
    this->str = src.str;
    return *this;
}

Data::~Data()
{
    std::cout << "Data deleted\n";
}

std::uintptr_t Data::serialize(Data* ptr)
{
    std::uintptr_t int_ptr = reinterpret_cast<std::uintptr_t>(ptr);
    return int_ptr;
}

Data* Data::deserialize(std::uintptr_t raw)
{
    Data* data_ptr = reinterpret_cast<Data*>(raw);
    return data_ptr;
}

std::string const& Data::getString()
{
    return this->str;
}