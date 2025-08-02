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

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> dataBase[2];
        
        void processFile(std::string fileName);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange& operator=(const BitcoinExchange &original);

        void loadDataBase(std::string fileName);
};

void handleFileName(std::string fileName);

#endif