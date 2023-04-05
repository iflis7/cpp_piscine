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

// BitcoinExchange::BitcoinExchange(std::string file, std::string input1, std::string input2)
// {
//     std::ifstream inputFile(input1.c_str());
//     if(!inputFile.good() || inputFile.peek() == std::ifstream::traits_type::eof())
//     {
//         std::ifstream csvFile(file.c_str());
//         if(!csvFile.good() || inputFile.peek() == std::ifstream::traits_type::eof())
//         {
//             std::cout << BOLD_RED << "Error: file not found or file empty." << RESET << std::endl;
//             exit(1);
//         }
//        this->inputInfo = getInputInfo(input2);
//     }
//     else
//     {
//         this->inputInfo = getInputInfo(input1);
//     }
//     std::ifstream csvFile(file.c_str());
//     if(!csvFile.good() || inputFile.peek() == std::ifstream::traits_type::eof())
//     {
//         std::cout << BOLD_RED << "Error: file not found or file empty." << RESET << std::endl;
//         exit(1);
//     }
//     //  std::ifstream file(filename.c_str());
//     // return file.peek() == std::ifstream::traits_type::eof();
//     // this->csvInfo = getCsvInfo(file);
//     // this->inputInfo = getInputInfo(input);
//     // printPairInfo(this->csvInfo);
//     // printPairInfo(this->inputInfo);
// }

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
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(std::string(date.c_str()).substr(0, 4).c_str());
    int month = std::atoi(std::string(date.c_str()).substr(5, 2).c_str());
    int day = std::atoi(std::string(date.c_str()).substr(8, 2).c_str());
    int currentYear = getCurrentYear();

    if (year < 2009 || year > currentYear)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::validPrice(float value)
{
    if (value < 0)
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
        if (std::getline(ss, dateStr, '|'))
        {
            std::string date = trim(dateStr);
            ss >> value;
            csvInfo.push_back(std::make_pair(date, value));
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
        for (std::deque<std::pair<std::string, float> >::iterator itr = this->csvInfo.begin();
             itr != this->csvInfo.end(); ++itr)
        {
            if (!validValueFormat(it->second, it->first))
                break;
            if (it->first == itr->first)
            {
                float val = it->second * itr->second;
                std::cout << it->first << "=> " << it->second << " = " << val << std::endl;
                break;
            }
            else
            {     
                std::pair<std::string, float> nearest = nearestDate(it->first, this->csvInfo);

                float val = it->second * nearest.second;
                std::cout << it->first << "=> " << it->second << " = " << val << std::endl;
                break;
            }
        }
     }
}

void exit_error(std::string str)
{
    std::cout << BOLD_RED << str << RESET << std::endl;
    exit(1);
}

std::pair<std::string, float> nearestDate(const std::string& date, const std::deque<std::pair<std::string, float> >& values)
{
    std::pair<std::string, float> result;


    for(std::deque<std::pair<std::string, float> >::const_iterator rit = values.begin(); rit != values.end(); ++rit) 
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
    }    
    return result;
}

