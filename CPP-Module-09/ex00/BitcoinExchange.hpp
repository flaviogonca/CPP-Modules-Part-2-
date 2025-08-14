/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:52:10 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/28 12:52:11 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> dataBase;
        void exchange(std::string date, std::string value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange& operator=(const BitcoinExchange &original);

        void loadDataBase(std::string fileName);
        void loadInputFile(std::string fileName);
};

void handleFileName(std::string fileName);
std::string trimmedStr(const std::string& s);
void chekValue(std::string value, int lineCount);
void checkDate(std::string date, int lineCount);

#endif