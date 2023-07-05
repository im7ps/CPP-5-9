/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:35:17 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 05:31:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T cont, int num)
{
    typename T::iterator it = std::find(cont.begin(), cont.end(), num);
    if (it == cont.end())
    {
        throw std::runtime_error("Value not found\n");
    }
    return it;
}

#endif