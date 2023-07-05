/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:32:34 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/03 23:32:35 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <cstdint>

class Data
{
    public:
        std::string str;

        Data();
        Data(std::string const& str);
        Data(Data const& cpy);
        Data& operator=(Data const& src);
        ~Data();

        std::string const& getString();
        uintptr_t   serialize(Data* ptr);
        Data*       deserialize(std::uintptr_t raw);
};

#endif