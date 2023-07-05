/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:23:57 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 17:27:08 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <string.h>
#include <iostream>
#include <cctype>
#include <stdlib.h>  
#include <iomanip>
#include <sstream>

class Converter
{
    private:
        char        c;
        int         num;
        float       fnum;
        double      dnum;
        std::string input;
    public:

        Converter();
        Converter(std::string const& str);
        Converter(Converter const& cpy);
        Converter& operator=(Converter const& src);
        ~Converter();

        bool    isChar(std::string input);
        bool    isInt(std::string input);
        bool    isFloat(std::string input);
        bool    isDouble(std::string input);
        bool    isInf(std::string input);

        void    printChar(char c);
        void    printInt(int num);
        void    printFloat(float fnum);
        void    printDouble(double dnum);
};

#endif