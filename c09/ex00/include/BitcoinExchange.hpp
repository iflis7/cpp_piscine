#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#pragma once

#include "../../doctest.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>

#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include <cctype>



class BitcoinExchange
{

private:
    std::vector<int> m_prices;
    // std::list<int> m_pricesList;

public:
    BitcoinExchange(std::string file, std::string input);
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    std::vector<std::pair<std::string, float> > getCsvInfo(std::string file);
    bool validDateFormat(std::string date);
    bool validPrice(float value);
    int getCurrentYear();
    std::vector<std::pair<std::string, float> > getInputInfo(std::string file);
    bool validValueFormat(int value);
    std::string trim(const std::string& str);
};

#endif // BITCOINEXCHANGE_HPP