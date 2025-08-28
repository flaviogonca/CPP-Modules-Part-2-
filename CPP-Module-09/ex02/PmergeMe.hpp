/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:04 by fmalungo          #+#    #+#             */
/*   Updated: 2025/08/27 19:21:27 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
    private:
        std::list<int> lst;
        std::vector<int> vet;

        int strToUnsignedInt(std::string str);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &original );
        PmergeMe& operator=(const PmergeMe &original );

        void loadInput(char **args);
};

#endif
