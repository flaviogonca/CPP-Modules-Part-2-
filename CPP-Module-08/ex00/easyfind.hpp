/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:22:10 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/21 15:22:12 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYTFIND_HPP
# define EASYTFIND_HPP

#include <list>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &data, int toFind)
{
    typename T::iterator it = std::find(data.begin(), data.end(), toFind);
    if (it == data.end())
        throw std::runtime_error("valor não encontrado");
    return it;
}

#endif
