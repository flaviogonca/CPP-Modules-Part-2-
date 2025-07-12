/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:56:27 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/07 09:56:29 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
    return *this;
}

void ScalarConverter::convert(const char* _str)
{
    std::string str = _str;
    char* endStr = NULL;

    double value = std::strtod(_str, &endStr);

    // Check if the input is a special float literal like 'nanf', 'inff', etc.
    bool isSpecialFloat = (str == "nanf" || str == "+inff" || str == "-inff");
    bool isSpecialDouble = (str == "nan" || str == "+inf" || str == "-inf");

    bool isFloatSuffix = (endStr && *endStr == 'f' && *(endStr + 1) == '\0');
    bool success = (endStr != _str && (*endStr == '\0' || isFloatSuffix)) || isSpecialFloat || isSpecialDouble;

    if (!success)
    {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: impossible" << std::endl
                  << "double: impossible" << std::endl;
        return;
    }

    // Print char
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    // Print int
    std::cout << "int: ";
    if (std::isnan(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // Print float
    std::cout << "float: ";
    float fval = static_cast<float>(value);
    if (std::isnan(fval))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(fval))
        std::cout << (fval < 0 ? "-inff" : "inff") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(fval == static_cast<int>(fval) ? 1 : 6)
                  << fval << "f" << std::endl;
    }

    // Print double
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "inf") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(value == static_cast<int>(value) ? 1 : 6)
                  << value << std::endl;
    }
}
