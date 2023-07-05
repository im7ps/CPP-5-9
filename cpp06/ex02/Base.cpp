/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:55:06 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/02 22:27:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base destructor called\n";
}

A::~A()
{
    std::cout << "A destructor called\n";
}

B::~B()
{
    std::cout << "B destructor called\n";
}

C::~C()
{
    std::cout << "C destructor called\n";
}

Base* generate(void)
{
    srand(time(0));
    int random = rand() % 3 + 1;

    switch (random)
    {
    case 1:
        return new A();
        break;
    case 2:
        return new B();
        break;
    case 3:
        return new C();
        break;
    default:
        break;
    }
    return nullptr;
}

//if else perché con un puntatore dynamic cast in caso di fallimento ritorna un nullptr
void identify(Base* p)
{
    if(dynamic_cast< A* >(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast< B* >(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast< C* >(p))
        std::cout << "C" << std::endl;
}


//try catch perché con un riferimento dynamic cast in caso di fallimento lancia una eccezione di tipo std::bad_cast
void identify(Base& p)
{
    try 
    {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A\n";
        (void)a;
    } 
    catch(const std::exception& e) {}
    try 
    {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B\n";
        (void)b;
    } 
    catch( const std::exception& e ) {}
    try 
    {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C\n";
        (void)c;
    } 
    catch( const std::exception& e ) {}
}
