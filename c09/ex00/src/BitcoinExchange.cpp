#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string file, std::string input)
{
    std::ifstream inputFile(input.c_str());
    
    if(!inputFile.good() || inputFile.peek() == std::ifstream::traits_type::eof())
        exit_error("Error: file not found, doesn't have the right permissions or empty.");

    std::ifstream csvFile(file.c_str());
    if(!csvFile.good() || inputFile.peek() == std::ifstream::traits_type::eof())
        exit_error("Error: file not found, doesn't have the right permissions or empty.");

    this->csvInfo = getCsvInfo(file);
    this->inputInfo = getInputInfo(input);
    // printPairInfo(this->csvInfo);
    // printPairInfo(this->inputInfo);
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange::~BitcoinExchange()" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    *this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        csvInfo = rhs.csvInfo;
        inputInfo = rhs.inputInfo;
    }
    return *this;
}

int BitcoinExchange::getCurrentYear()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    return localTime->tm_year + 1900;
}

bool BitcoinExchange::validDateFormat(std::string date)
{
    // if (date.length() < 9 && date.length() > 10)
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(std::string(date.c_str()).substr(0, 4).c_str());
    int month = std::atoi(std::string(date.c_str()).substr(5, 2).c_str());
    int day = std::atoi(std::string(date.c_str()).substr(8, 2).c_str());
    int currentYear = getCurrentYear();

    if (year < 2009)
    {
        std::cout << BOLD_YELLOW << "Error: Bitcoin wasn't invented yet!!! " << RESET;
        return false;
    }
    // if (year > currentYear)
    // {
    //     std::cout << BOLD_YELLOW << "Error: Year Can't be after 2023   !!! " << RESET;
    //     return false;
    // }
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::validValueFormat(float value, std::string date)
{
    if (value == std::string::npos || !validDateFormat(date))
    {
        std::cout << BOLD_RED << "Error: bad input => " << RESET << date << std::endl;
        return (false);
    }
    else if (value < 0)
    {
        std::cout << BOLD_RED <<  "Error: not a positive number." << RESET << std::endl;
        return (false);
    }
    else if (value > 1000)
    {
        std::cout << BOLD_RED <<  "Error: too large a number." << RESET << std::endl;
        return (false);
    }
    return (true);
}

void BitcoinExchange::printPairInfo(std::deque<std::pair<std::string, float> > pair)
{
    for (std::deque<std::pair<std::string, float> >::iterator it = pair.begin(); it != pair.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << std::endl;
}

std::string BitcoinExchange::trim(const std::string &str)
{
    std::string::size_type first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    std::string::size_type last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

std::deque<std::pair<std::string, float> > BitcoinExchange::getCsvInfo(std::string file)
{
    std::deque<std::pair<std::string, float> > csvInfo;
    std::ifstream csvFile(file.c_str());
    if (!csvFile.good())
        std::cout << "File is not good" << std::endl;
    std::string line;
    std::string date;
    float value;
    std::getline(csvFile, line); // skip the first line (date,exchange_rate)
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> value;
        csvInfo.push_back(std::make_pair(date, value));
    }
    return csvInfo;
}

std::deque<std::pair<std::string, float> > BitcoinExchange::getInputInfo(std::string file)
{
    std::deque<std::pair<std::string, float> > csvInfo;
    std::ifstream csvFile(file.c_str());
    std::string line;
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        float value;
        std::string strValue;
        if (std::getline(ss, dateStr, '|'))
        {
            std::string date = trim(dateStr); // trim removes whitespace from the string
            ss >> strValue;
            std::string::size_type pos = strValue.find(',');

            if (pos != std::string::npos && date != "date")
            {
                strValue.replace(pos, 1, ".");
                value = std::atof(strValue.c_str());
                value = std::atof(strValue.c_str());
                csvInfo.push_back(std::make_pair(date, value));
            }
            else if (pos == std::string::npos && date != "date")
            {
                value = std::atof(strValue.c_str());
                csvInfo.push_back(std::make_pair(date, value));
            }
            else if(date != "date")
                csvInfo.push_back(std::make_pair(date, std::string::npos));
        }
        else
             exit_error("Invalid value format. Should be like: <date | value>");
    }
    return csvInfo;
}

void BitcoinExchange::run()
{
    for (std::deque<std::pair<std::string, float> >::iterator it = this->inputInfo.begin();
         it != this->inputInfo.end(); it++)
    {
        while (!validValueFormat(it->second, it->first))
        {
            it++;
            if(it == this->inputInfo.end())
                return;    
        }
       
        for (std::deque<std::pair<std::string, float> >::iterator itr = this->csvInfo.begin();
             itr != this->csvInfo.end(); ++itr)
        {
            if (it->first == itr->first)
            {
                float val = it->second * itr->second;
                std::cout <<  it->first << "=> " << std::fixed << std::setprecision(2) << it->second 
                    << " = " << std::fixed << std::setprecision(2) << val << std::endl;
            }
        }
        std::pair<std::string, float> nearest = nearestDate(it->first, this->csvInfo);
        if (!nearest.first.empty())
        {
            float val = it->second * nearest.second;
            std::cout << it->first << "=> " << std::fixed << std::setprecision(2) << nearest.second 
                << " = " << std::fixed << std::setprecision(2) << val << std::endl;
        }
     }
}

std::pair<std::string, float> nearestDate(const std::string& date, const std::deque<std::pair<std::string, float> >& values)
{
    std::pair<std::string, float> result;

    for(std::deque<std::pair<std::string, float> >::const_iterator rit = values.begin(); rit != values.end(); rit++)
    {
        int i = std::distance(values.begin(), rit);
        if(rit != values.end() - 1)
            i++;
        if(rit->first < date && values.at(i).first > date)
        {
            result.first = rit->first;
            result.second = rit->second;
            return(result);
        }
        else if(rit->first < date && rit == values.end() - 1)
        {
            result.first = rit->first;
            result.second = rit->second;
            return result;
        }
        else if(rit->first > date && rit == values.begin())
        {
            result.first = rit->first;
            result.second = rit->second;
            return(result);
        }
    }    
    return result;
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void exit_error(std::string str)
{
    std::cout << BOLD_RED << str << RESET << std::endl;
    exit(1);
}
