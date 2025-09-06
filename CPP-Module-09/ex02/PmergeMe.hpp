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

#include <deque>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
    private:
        std::deque<int> deq;
        std::vector<int> vet;

        int strToUnsignedInt(std::string str);
        std::vector<int> jacobsthal(size_t n);
        template <typename T>
        void insertSmalls(T &bigs, T &smalls)
        {
            std::vector<int> order = jacobsthal(smalls.size());
            std::vector<bool> used(smalls.size() , false);
            if (static_cast<int> (order.size()) <= 2)
            {
                bigs.insert(bigs.begin(), *(smalls.begin()));
                return ;
            }
            int i = 1;
            while (++i < static_cast<int> (order.size()))
            {
                int value = *(smalls.begin() + order[i] - 1);
                typename T::iterator it = lower_bound(bigs.begin(), bigs.end(), value);
                bigs.insert(it, value);
                used[order[i] - 1] = true;
            }
            i = -1;
            while (++i < static_cast<int> (used.size()))
            {
                if (used[i] == false)
                {
                    int value = *(smalls.begin() + i);
                    typename T::iterator it = lower_bound(bigs.begin(), bigs.end(), value);
                    bigs.insert(it, value);
                    used[i] = true;
                }
            }
        }

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &original );
        PmergeMe& operator=(const PmergeMe &original );

        void loadInput(char **args);
        void sort();

        template <typename T>
        void  printContainerElements(T c)
        {
            typename T::iterator it = c.begin();
            while (it != c.end())
                std::cout  << " " << *it++;
            std::cout << std::endl;
        }

        template <typename T>
        T mergeInsertion(T data)
        {
            T       bigs;
            T       smalls;
            int     extra;
            bool    leftover = 0;
            typename T::iterator it = data.begin();

            if ((data.size() % 2) != 0)
            {
                leftover = 1;
                extra = *(data.end() - 1);
                data.pop_back();
            }
            size_t i = 0;
            size_t x = 0;
            while (i < (data.size() / 2 ))
            {
                if (*(it + x) > *(it + x + 1))
                {
                    bigs.push_back(*(it + x));
                    smalls.push_back(*(it + x + 1));
                }
                else
                {
                    bigs.push_back(*(it + x + 1));
                    smalls.push_back(*(it + x));
                }
                i++;
                x += 2;
            } 

            if (bigs.size() > 2)
                bigs = mergeInsertion(bigs);

            if (bigs.size() == 2 && bigs.front() > bigs.back())
                std::swap(bigs.front(), bigs.back());

            insertSmalls(bigs, smalls);

            if (leftover)
            {
                typename T::iterator iter = lower_bound(bigs.begin(), bigs.end(), extra);
                bigs.insert(iter, extra);
            }
            return bigs;
        }
};

#endif
