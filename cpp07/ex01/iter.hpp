/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:00:46 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 02:29:02 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void print_value(T* array)
{
    std::cout << *array << std::endl;
}

template <typename T>
void iter(T* array, size_t length, void(*print_value)(T*))
{
    size_t i = 0;

    while (i < length)
    {
        print_value(&array[i]);
        ++i;
    }
}


class MyClass
{
public:
    MyClass(int value) : data(value) {}

    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj)
    {
        os << obj.data;
        return os;
    }

private:
    int data;
};

#endif