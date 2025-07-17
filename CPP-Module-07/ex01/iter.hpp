/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:46:07 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/17 17:46:09 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *address, size_t size, void (*f)(T &))
{
    try
    {
        for (size_t i = 0; i < size; i++)
            (*f)(address[i]);
    }
    catch(const std::exception& e)
    {
    }
    
}

template <typename T>
void iter(const T *address, const size_t size, void (*f)(const T &))
{
    for (size_t i = 0; i < size; i++)
        (*f)(address[i]);
}

template<typename T>
void showElement(const T& x)
{
    std::cout << x << " ";
}
#endif
