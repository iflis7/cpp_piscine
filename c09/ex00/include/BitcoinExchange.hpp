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
#include <list>

class BitcoinExchange
{

private:
    std::deque<std::pair<std::string, float> > csvInfo;
    std::deque<std::pair<std::string, float> > inputInfo;
    // std::vector<std::pair<std::string, float> > csvInfo;
    // std::vector<std::pair<std::string, float> > inputInfo;


public:
    BitcoinExchange(std::string file, std::string input);
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    // std::vector<std::pair<std::string, float> > getCsvInfo(std::string file);
    // std::list<std::pair<std::string, float> > getCsvInfo(std::string file);
    std::deque<std::pair<std::string, float> > getCsvInfo(std::string file);

    // std::vector<std::pair<std::string, float> > getInputInfo(std::string file);
    // std::list<std::pair<std::string, float> > getInputInfo(std::string file);
    std::deque<std::pair<std::string, float> > getInputInfo(std::string file);
    bool validDateFormat(std::string date);
    bool validPrice(float value);
    int getCurrentYear();
    bool validValueFormat(float value, std::string date);
    std::string trim(const std::string& str);
    void printPairInfo(std::deque<std::pair<std::string, float> > pair);
    void run();
};

#endif