/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:47:09 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/05 00:08:30 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
    ;
}

Span::Span(size_t N) : N(N)
{
    ;
}

Span::Span(Span const& cpy)
{
    this->N = cpy.N;
    this->myarray = cpy.myarray;
}

Span& Span::operator=(Span const& src)
{
    if (this != &src)
    {
        this->N = src.N;
        this->myarray = src.myarray;
    }
    return *this;
}

Span::~Span()
{
    ;
}

void Span::addNumber(int num)
{
    if (myarray.size() < N)
    {
        myarray.push_back(num);
    }
    else
    {
        throw arrayAlredyFull();
    }
}

int Span::shortestSpan()
{
    int tmp = 2147483647;
    std::sort(myarray.begin(), myarray.end());
    
    std::vector<int>::iterator it = myarray.begin();
    std::vector<int>::iterator next = it + 1;
    while (next != myarray.end())
    {
        if (*next - *it < tmp)
            tmp = *next - *it;
        ++next;
        ++it;
    }
    return tmp;
}

int Span::longestSpan()
{
    std::sort(myarray.begin(), myarray.end());
    return (*(myarray.end() - 1) - *(myarray.begin()));
}

void Span::addNumbers(int count, ...)
{
    int i = 0;
    va_list args;
    va_start(args, count);
    while (i < count)
    {
        int num = va_arg(args, int);
        addNumber(num);
        ++i;
    }
    va_end(args);
}
