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
        this->vet = original.vet;
        this->deq = original.deq;
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
        if ((std::find(deq.begin(), deq.end(), strToUnsignedInt(*args))) != deq.end())
            throw std::runtime_error("Error");
        deq.push_back(strToUnsignedInt(*args));
        vet.push_back(strToUnsignedInt(*args));
        args++;
    }
    std::string str;
}

std::vector<int> PmergeMe::jacobsthal(size_t n)
{
    int value;
    std::vector<int> jacobSeq;

    jacobSeq.push_back(0);
    jacobSeq.push_back(1);

    while (static_cast<size_t> (jacobSeq.back()) < n)
    {
        value = jacobSeq.back() + 2*(jacobSeq[jacobSeq.size() - 2]);
        jacobSeq.push_back(value);
    }
    jacobSeq.pop_back();
    return jacobSeq;
}

void PmergeMe::sort()
{
    double vetTime;
    double deqTime;

    std::cout << "Before:"; printContainerElements(this->vet);
    clock_t vetBegin = clock();
    std::vector<int> result = mergeInsertion(this->vet);
    clock_t vetEnd = clock();
    std::cout << "After:"; printContainerElements(result);

    clock_t deqBegin = clock();
    std::deque<int> deqResult = mergeInsertion(this->deq);
    clock_t deqEnd = clock();

    vetTime = static_cast<double> (vetEnd - vetBegin) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vet.size()
          << " elements with std::vector : " << std::fixed << std::setprecision(5)
          << vetTime << " us" << std::endl;

    deqTime = static_cast<double> (deqEnd - deqBegin) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deq.size()
          << " elements with std::deque : " << std::fixed << std::setprecision(5)
          << deqTime << " us" << std::endl;
}