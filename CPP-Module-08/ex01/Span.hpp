/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:39 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/23 12:44:41 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vect;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& original);
        Span operator=(const Span& original);
        ~Span();

        void addNumber(int value);
        int shortestSpan();
        int longestSpan();

        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }
};

#endif
