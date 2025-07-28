/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:32:15 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/23 19:32:16 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack& original) : std::stack<T>(original) {};
        MutantStack &operator=(const MutantStack& original) {
            if (this != &original)
                 std::stack<T>::operator=(original);
            return *this;
        };
        virtual ~MutantStack() {};

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()  { return this->c.begin(); }
        iterator end()  { return this->c.end(); }
};

#endif
