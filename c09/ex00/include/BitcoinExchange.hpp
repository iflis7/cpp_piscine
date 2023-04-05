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
#include <deque>
#include <map>


#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_BLUE "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN "\033[1m\033[36m"

class BitcoinExchange
{

private:
    std::deque<std::pair<std::string, float> > csvInfo;
    std::deque<std::pair<std::string, float> > inputInfo;

public:
    BitcoinExchange();
    BitcoinExchange(std::string file, std::string input);
    BitcoinExchange(std::string file, std::string input1, std::string input2);
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    std::deque<std::pair<std::string, float> > getCsvInfo(std::string file);
    std::deque<std::pair<std::string, float> > getInputInfo(std::string file);
    bool validDateFormat(std::string date);
    bool validPrice(float value);
    int getCurrentYear();
    bool validValueFormat(float value, std::string date);
    std::string trim(const std::string& str);
    void printPairInfo(std::deque<std::pair<std::string, float> > pair);
    
    void run();
};

void exit_error(std::string str);
std::pair<std::string, float> nearestDate(const std::string& date, 
    const std::deque<std::pair<std::string, float> >& values);

#endif

