/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:24:31 by fmalungo          #+#    #+#             */
/*   Updated: 2025/08/27 19:24:34 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &original) { *this = original; }

PmergeMe& PmergeMe::operator=(const PmergeMe &original)
{
    if (this != &original)
    {
        
    }
    return *this;
}

int PmergeMe::strToUnsignedInt(std::string str)
{
    int nbr;
    std::stringstream ss(str);

    if (!(ss >> nbr) || nbr < 0)
        throw std::runtime_error("Error");
    return nbr;
}

void PmergeMe::loadInput(char **args)
{
    while (*args)
    {
        if ((std::find(lst.begin(), lst.end(), strToUnsignedInt(*args))) != lst.end())
            throw std::runtime_error("Error");
        lst.push_back(strToUnsignedInt(*args));
        vet.push_back(strToUnsignedInt(*args));
        std::cout << strToUnsignedInt(*args) << "\n";
        args++;
    }
    std::string str;
}
