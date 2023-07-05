/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:34:16 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 03:52:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T*      elements;
        size_t  size;
    public:
        Array();
        Array(size_t n);
        Array(Array const& cpy);
        Array& operator=(Array const& src);
        ~Array();

        size_t getSize() const;

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
};

#include "Array.tpp"

#endif