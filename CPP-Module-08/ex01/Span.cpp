/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:33 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/23 12:44:34 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(3) {}

Span::~Span() {}

Span::Span(unsigned int N): N(N) {}

Span::Span(const Span& original)
{
        this->N =original.N;
        this->vect = original.vect;
}

Span Span::operator=(const Span& original)
{
    if (this != &original)
    {
        this->N =original.N;
        this->vect = original.vect;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (this->vect.size() == this->N)
        throw std::runtime_error("Limits to add numbers is over");
    this->vect.push_back(value);
}

int Span::shortestSpan()
{
    if (this->vect.size() <= 1)
        throw std::runtime_error("No span can be found.");
    std::vector<int> tmp = this->vect;
    std::sort(tmp.begin(), tmp.end(), std::greater<int>());
    std::vector<int>::iterator it = tmp.begin();
    Span span(tmp.size() - 1);
    for (size_t i = 0; i < (tmp.size() - 1); i++)
        span.addNumber( *(it + i) - *(it + i + 1));
    std::sort(span.vect.begin(), span.vect.end());
    it = span.vect.begin();
    return *it;
}

int Span::longestSpan()
{
    if (this->vect.size() <= 1)
        throw std::runtime_error("No span can be found.");
    std::vector<int> tmp = this->vect;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it = tmp.begin();
    return *(it + tmp.size() - 1) - *it;
}
