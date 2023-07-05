/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:23:51 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/05 01:09:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{
    this->c = '0';
    this->num = 0;
    this->fnum = 0.0f;
    this->dnum = 0.0;
    std::cout << "Converted created\n";
}

Converter::Converter(std::string const& str)
{
    this->input = str;

    if (this->isInt(input))
    {
        return ;
    }
    else if (this->isChar(input))
    {
        return ;
    }
    else if (this->isDouble(input))
    {
        return ;
    }
    else if (this->isFloat(input))
    {
        return ;
    }
    else if (this->isInf(input))
    {
        return ;
    }
    else
        std::cout << "Input error\n";
    return ;
}

Converter::Converter(Converter const& cpy)
{
    *this = cpy;
}

Converter& Converter::operator=(Converter const& src)
{
    this->input = src.input;
    this->c = src.c;
    this->num = src.num;
    this->fnum = src.fnum;
    this->dnum = src.dnum;
    return *this;
}

Converter::~Converter()
{
    std::cout << "Converted deleted\n";
}

bool Converter::isChar(std::string input)
{
    if (input.length() == 1 && ((input[0] > 32 && input[0] < 48) || (input[0] > 57 && input[0] < 127)))
    {
        this->c = input[0];
        printChar(input[0]);
        return true;
    }
    return false;
}

bool Converter::isInt(std::string input)
{
    size_t i = 0;

    if (input[0] == '-' || input[0] == '+')
        ++i;
    while (i < input.length())
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
        ++i;
    }
    this->num = atoi(input.c_str());
    printInt(num);
    return true;
}

bool Converter::isDouble(std::string input)
{
    size_t      i = 0;
    bool        onePoint = false;
    
    if (input[0] == '-' || input[0] == '+')
        ++i;

    while (i < input.length())
    {
        if (input[i] == '.' && onePoint == false)
        {
            onePoint = true;
            ++i;
            continue;
        }
        if (!isdigit(input[i]))
        {
            return false;
        }
        ++i;
    }
    this->dnum = atof(input.c_str());
    printDouble(dnum);
    return true;
}

bool Converter::isFloat(std::string input)
{
    size_t      i = 0;
    bool        onePoint = false;
    
    if (input[0] == '-' || input[0] == '+')
        ++i;

    while (i < input.length())
    {
        if (input[i] == '.' && onePoint == false)
        {
            onePoint = true;
            ++i;
            continue ;
        }
        if (input[i] == 'f' && i == input.length() - 1)
        {
            ++i;
            continue ;
        }
        if (!isdigit(input[i]))
            return false;
        ++i;
    }
    this->fnum = atof(input.c_str());
    printFloat(fnum);
    return true;
}

bool Converter::isInf(std::string input)
{
    if (input.compare("nan") == 0 || input.compare("-inf") == 0 || input.compare("+inf") == 0)
    {
        std::cout << "char : impossible\n";
        std::cout << "int : impossible\n";
        std::cout << "float : " << input << "f\n";
        std::cout << "double : " << input << std::endl; 
        return(true);
    }
    return(false);
}

void Converter::printChar(char c)
{
    this->c = c;
    this->num = c;
    this->dnum = static_cast<double>(this->num);
    this->fnum = static_cast<float>(this->num);

    std::cout << "char : " << this->c << std::endl;
    std::cout << "int : " << this->num << std::endl;
    std::cout << "double : "<< std::fixed << std::setprecision(1) << this->dnum << std::endl;
    std::cout << "float : "<< std::fixed << std::setprecision(1) <<  this->fnum << "f" << std::endl;
}

void Converter::printInt(int num)
{
    this->num = num;
    this->fnum = static_cast<float>(this->num);
    this->dnum = static_cast<double>(this->num);
    
    if (this->num <= 31 || this->num == 127)
        std::cout << "char : non displayable\n";
    else
    {
        this->c = this->num;
        std::cout << "char : " << this->c << std::endl;
    }
    std::cout << "int : " << this->num << std::endl;
    std::cout << "double : "<<std::fixed << std::setprecision(1) << this->dnum << std::endl; 
    std::cout << "float : "<<std::fixed << std::setprecision(1) <<  this->fnum << "f" << std::endl; 
}

void Converter::printDouble(double dnum)
{
    this->num = dnum;
    this->dnum = dnum;
    this->fnum = static_cast<float>(this->dnum);
    
    if (this->num <= 31 || this->num == 127)
        std::cout << "char : non displayable\n";
    else
    {
        this->c = this->num;
        std::cout << "char : " << this->c << std::endl;
    }
    std::cout << "int : " << this->num << std::endl;
    std::cout << "double : "<<std::fixed << std::setprecision(1) << this->dnum << std::endl; 
    std::cout << "float : "<<std::fixed << std::setprecision(1) <<  this->fnum << "f" << std::endl; 
}

void Converter::printFloat(float fnum)
{
    this->num = fnum;
    this->fnum = fnum;
    this->dnum = static_cast<double>(this->fnum);
    
    if (this->num <= 31 || this->num == 127)
        std::cout << "char : non displayable\n";
    else
    {
        this->c = this->num;
        std::cout << "char : " << this->c << std::endl;
    }
    std::cout << "int : " << this->num << std::endl;
    std::cout << "double : "<<std::fixed << std::setprecision(1) << this->dnum << std::endl; 
    std::cout << "float : "<<std::fixed << std::setprecision(1) <<  this->fnum << "f" << std::endl; 
}