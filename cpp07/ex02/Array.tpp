/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:24:43 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/04 03:56:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : elements(nullptr), size(0)
{
    ;
}

template <typename T>
Array<T>::Array(size_t size) : size(size)
{
    elements = new T[size];
}

template <typename T>
Array<T>::Array(Array const& cpy)
{
    this->size = cpy.size;
    elements = new T[size];

    size_t i = 0;
    while (i < size)
    {
        this->elements[i] = cpy.elements[i];
        ++i;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& cpy)
{
    if (this != cpy)
    {
        this->size = cpy.size;
        delete elements;
        elements = new T[size];

        size_t i = 0;
        while (i < size)
        {
            this->elements[i] = cpy.elements[i];
            ++i;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete elements;
}

template <typename T>
size_t Array<T>::getSize() const
{
    return this->size;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index > this->size)
    {
        throw std::out_of_range("Segmentation fault\n");
    }
    return this->elements[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index > this->size)
    {
        throw std::out_of_range("Segmentation fault\n");
    }
    return this->elements[index];
}
