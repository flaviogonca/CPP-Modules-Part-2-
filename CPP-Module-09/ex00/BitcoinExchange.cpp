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

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
        dataBase = original.dataBase;
    }
    return *this;
}

std::string trimmedStr(const std::string &s)
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

void BitcoinExchange::exchange(std::string date, std::string value)
{
    float _value;
    std::stringstream ss(value);

    ss >> _value;
    std::map<std::string, float>::const_iterator iterator = this->dataBase.upper_bound(date);
    if (iterator == this->dataBase.end())
        throw std::runtime_error("Error: theres is no an exchange rate for: " + date);
    --iterator;
    std::cout << date << " => " << value << " = " << _value * iterator->second << std::endl;
}

void chekValue(std::string value, int lineCount)
{
    float num;
    std::stringstream ss(value);

    if (!(ss >> num)) {
        throw std::runtime_error("Invalid Value at line " + intToStr(lineCount) + ": " + value);
    }
    int pontos = 0;
    for (size_t i = 0; value[i]; i++) {
        if (value[i] == '.') {
            pontos++;
            if (pontos > 1) {
                throw std::runtime_error("Invalid Value at line " + intToStr(lineCount) + ": " + value);
            }
        }
        else if (!std::isdigit(static_cast<unsigned char>(value[i]))) {
            throw std::runtime_error("Invalid Value at line " + intToStr(lineCount) + ": " + value);
        }
    }
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

    std::stringstream ss0(date.substr(0, 4));
    std::stringstream ss1(date.substr(5, 2));
    std::stringstream ss2(date.substr(8, 2));

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

void handleFileName(std::string fileName)
{
    size_t size = fileName.length();
    if (fileName.at(size - 1) == 'v' && fileName.at(size - 2) == 's' && fileName.at(size - 3) == 'c' && fileName.at(size - 4) == '.' && (size - 4) != 0)
        return;

    throw std::runtime_error("Wrong file extansion");
}

void BitcoinExchange::loadDataBase(std::string fileName)
{
    size_t index = 1;
    std::string line;
    std::string date;
    std::string valueHeader;
    std::string extraCol;
    float value;

    handleFileName(fileName);
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    while (line.empty())
        if (!std::getline(file, line))
            throw std::runtime_error("Error: database file is empty");

    std::stringstream ss(line);

    if (!std::getline(ss, date, ',') || !std::getline(ss, valueHeader, ','))
        throw std::runtime_error("Wrong Header in the database file");

    if (std::getline(ss, extraCol, ','))
        throw std::runtime_error("Database error: Extra colunm at line " + intToStr(index));

    date = trimmedStr(date);
    valueHeader = trimmedStr(valueHeader);
    if (date != "date" || valueHeader != "exchange_rate")
        throw std::runtime_error("Wrong Header in the database file");

    while (std::getline(file, line))
    {
        ++index;
        std::stringstream ss2(line);
        if (!std::getline(ss2, date, ',') || !std::getline(ss2, valueHeader, ','))
            throw std::runtime_error("Database error: Issue at line " + intToStr(index));
        if (std::getline(ss2, extraCol, ','))
            throw std::runtime_error("Database error: Extra colunm at line " + intToStr(index));

        date = trimmedStr(date);
        valueHeader = trimmedStr(valueHeader);
        checkDate(date, index);
        std::istringstream ss3(valueHeader);
        ss3 >> value;
        dataBase[date] = value;
    }
    file.close();
}

void BitcoinExchange::loadInputFile(std::string fileName)
{
    size_t index = 1;
    std::string line;
    std::string date;
    std::string valueHeader;
    std::string extraCol;

    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    while (line.empty())
        if (!std::getline(file, line))
            throw std::runtime_error("Error: input file is empty");

    std::stringstream ss(line);

    if (!std::getline(ss, date, '|') || !std::getline(ss, valueHeader, ','))
        throw std::runtime_error("Wrong Header in the input file");

    try
    {
        if (std::getline(ss, extraCol, '|'))
            throw std::runtime_error("Input file, error: Extra colunm at line " + intToStr(index));

        date = trimmedStr(date);
        valueHeader = trimmedStr(valueHeader);
        if (date != "date" || valueHeader != "value")
            throw std::runtime_error("Wrong Header in the input file");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    while (std::getline(file, line))
    {
        try
        {
            ++index;
            std::stringstream ss2(line);
            if (!std::getline(ss2, date, '|') || !std::getline(ss2, valueHeader, ','))
                throw std::runtime_error("Input file, error: Issue at line " + intToStr(index));
            if (std::getline(ss2, extraCol, '|'))
                throw std::runtime_error("Input file, error: Extra colunm at line " + intToStr(index));

            date = trimmedStr(date);
            valueHeader = trimmedStr(valueHeader);
            checkDate(date, index);
            chekValue(valueHeader, index);
            this->exchange(date, valueHeader);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}