/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mulist.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 00:23:13 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/05 02:03:34 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    const_iterator begin() const
    {
        return this->c.begin();
    }

    const_iterator end() const
    {
        return this->c.end();
    }
};

// template <typename T>
// class MutantStack : public std::list<T>
// {
// public:
//     typedef typename std::list<T>::iterator iterator;
//     typedef typename std::list<T>::const_iterator const_iterator;

//     iterator begin()
//     {
//         return std::list<T>::begin();
//     }

//     iterator end()
//     {
//         return std::list<T>::end();
//     }

//     const_iterator begin() const
//     {
//         return std::list<T>::begin();
//     }

//     const_iterator end() const
//     {
//         return std::list<T>::end();
//     }
// };

#endif