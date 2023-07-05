/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:55:09 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 20:55:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
    public:
        ~A();
};

class B : public Base
{
    public:
        ~B();
};

class C : public Base
{
    public:
        ~C();
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif