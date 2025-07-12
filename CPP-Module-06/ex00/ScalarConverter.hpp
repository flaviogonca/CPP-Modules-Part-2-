/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:56:19 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/07 09:56:20 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& original);
        ScalarConverter& operator=(const ScalarConverter& original);

        static bool isChar(std::string str);
        static bool isInt(std::string str);

        static void toChar(std::string str);
        static void toInt(std::string str);
        
    public:
        ~ScalarConverter();

        static void convert(const char* _str);
};

#endif
