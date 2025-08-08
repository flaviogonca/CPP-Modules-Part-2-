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

std::string intToStr(int value)
{
    std::stringstream ss;
    ss << value;

    return ss.str();
}

void chekValue(std::string value, int lineCount)
{
    float num;
    std::stringstream ss(value);
    
    ss >> num;
    if (num < 0 || num > 1000)
        throw std::runtime_error("Invalid Value at line " + intToStr(lineCount) + ": " + ss.str());
}

void checkDate(std::string date, int lineCount)
{
    int yy;
    int mm;
    int dd;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Invalid Date Format at line " + intToStr(lineCount) + ": " + date);
        
    std::stringstream ss0(date.substr(0,4));
    std::stringstream ss1(date.substr(5,2));
    std::stringstream ss2(date.substr(8,2));

    ss0 >> yy;
    ss1 >> mm;
    ss2 >> dd;

    if (yy < 2009 || mm > 12 || mm < 1 || dd < 1 || dd > 31)
        throw std::runtime_error("Invalid Date at line " + intToStr(lineCount) + ": " + date);
        
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0))
        daysInMonth[1] = 29;
    
    if (dd > daysInMonth[mm - 1])
        throw std::runtime_error("Invalid Day at line " + intToStr(lineCount) + ": " + date);
}

void BitcoinExchange::processFile(std::string fileName)
{
    size_t index = 1;
    std::string line;
    std::string date;
    std::string valueHeader;
    // float value;

    std::ifstream file(fileName.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    while (line.empty())
        if (!std::getline(file, line))
            throw std::runtime_error("Error: empty database fil");

    std::stringstream ss(line);

    if (!std::getline(ss, date, ',') || !std::getline(ss, valueHeader, ','))
        throw std::runtime_error("Wrong Header in the database file");    

    ss.clear();
    date = trimmedStr(date);
    valueHeader = trimmedStr(valueHeader);
    if (date != "date" || valueHeader != "exchange_rate")
        throw std::runtime_error("Wrong Header in the database file");    
        
    checkDate("2025-02-02", index);
    // std::stringstream ss2(line);
    // while (std::getline(file, line))
    // {
        // if (std::getline(ss2, date, ','))
        // std::cout << line << std::endl;
    // }

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