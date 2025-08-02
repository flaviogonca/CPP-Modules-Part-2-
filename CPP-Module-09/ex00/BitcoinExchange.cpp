/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:52:04 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/28 12:52:05 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    loadDataBase("");
    loadDataBase("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    loadDataBase(fileName);
    loadDataBase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    dataBase[0] = original.dataBase[0];
    dataBase[1] = original.dataBase[1];
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
        dataBase[0] = original.dataBase[0];
        dataBase[1] = original.dataBase[1];
    }
    return *this;
}

void BitcoinExchange::processFile(std::string fileName)
{
    size_t index = 1;
    if (fileName.compare("data.csv"))
        --index;
    
}

void handleFileName(std::string fileName)
{
    size_t size = fileName.length();
    if(fileName.at(size - 1) == 'v' && fileName.at(size - 2) == 's' && fileName.at(size - 3) == 'c' && fileName.at(size - 4) == '.' && (size - 4) != 0)
        return ;
    throw std::runtime_error("Wrong file extansion");
}

void BitcoinExchange::loadDataBase(std::string fileName)
{
    handleFileName(fileName);
    processFile(fileName);
}