#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "../../doctest.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

class BitcoinExchange
{

private:
    std::vector<int> m_prices;
    std::list<int> m_pricesList;

public:
    BitcoinExchange(std::string file);
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    int maxProfit();
    int maxProfitList();
    bool validDateForamt();
    bool validValueFormat();
    bool validInput();
    std::vector<std::pair<std::string, float> > getCsvInfo(std::string file);
};

#endif // BITCOINEXCHANGE_HPP