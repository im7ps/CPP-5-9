/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:42:31 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/05 00:08:35 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <cstdarg>

class Span
{
    private:
        size_t N;
        std::vector<int> myarray;
    public:
        Span();
        Span(size_t N);
        Span(Span const& cpy);
        Span& operator=(Span const& src);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        void addNumbers(int count, ...);

        class arrayAlredyFull : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Array alredy full\n";
                }
        };
};

#endif