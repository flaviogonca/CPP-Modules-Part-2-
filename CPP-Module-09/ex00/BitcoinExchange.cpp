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
    loadDataBase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    dataBase = original.dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
        dataBase = original.dataBase;
    }
    return *this;
}

std::string trimmedStr(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return ""; 
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}

bool checkDateFormat(std::string date)
{

}

void BitcoinExchange::processFile(std::string fileName)
{
    size_t index = 1;
    std::string line;
    std::string date;
    std::string valueHeader;
    float value;

    std::ifstream file(fileName.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    while (line.empty())
        if (!std::getline(file, line))
            throw std::runtime_error("Error: empty database fil");

    std::stringstream ss(line);

    if (!std::getline(ss, date, ',') || !std::getline(ss, valueHeader, ','))
        throw std::runtime_error("Wrong Header in the database file");    

    date = trimmedStr(date);
    valueHeader = trimmedStr(valueHeader);
    if (date != "date" || valueHeader != "exchange_rate")
        throw std::runtime_error("Wrong Header in the database file");    

    while (std::getline(file, line))
    {
        // std::stringstream ss2(line);
        // if (std::getline(ss2, date, ','))
        std::cout << line << std::endl;
    }

    std::cout << fileName << " opened sucessfully -> " << index << std::endl;

    file.close();
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
    // handleFileName(fileName);
    processFile(fileName);
}