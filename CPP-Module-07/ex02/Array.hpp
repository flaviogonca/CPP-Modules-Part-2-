/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:30:27 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/17 19:30:28 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int n;

    public:
        Array(): elements(NULL), n(0) {};
        ~Array() { delete[] elements; };
        Array(unsigned int n): elements(new T[n]), n(n) {};
        Array(const Array& original)
        {
            n = original.n;
            elements = new T[n];
            for (size_t i = 0; i < n; i++)
                elements[i] = original.elements[i];
        }
        Array& operator=(const Array& original)
        {
            if (this != &original)
            {
                delete[] elements;
                n = original.n;
                elements = new T[n];
                for (size_t i = 0; i < n; i++)
                elements[i] = original.elements[i];
            }
            return *this;
        }
        T& operator[](const unsigned int& i)
        {
            if (i >= this->n)
                throw std::out_of_range("index is out of bounds");
            return this->elements[i];
        }
        const T& operator[](const unsigned int& i) const
        {
            if (i >= this->n)
                throw std::out_of_range("index is out of bounds");
            return this->elements[i];
        }
        void setElementValue(T value, int pos){elements[pos] = value;}
        T& getElementValue(int pos){return elements[pos];}
};

#endif
