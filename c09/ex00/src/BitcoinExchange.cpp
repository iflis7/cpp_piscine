#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file, std::string input)
{
    // std::cout << "BitcoinExchange::BitcoinExchange()" << std::endl;
    std::cout << "file: " << file << std::endl;
    std::vector<std::pair<std::string, float> > csvInfo = getCsvInfo(file);

    std::cout << "file1: " << file << std::endl;
    for (std::vector<std::pair<std::string, float> >::iterator it = csvInfo.begin(); it != csvInfo.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    // std::cout << "BitcoinExchange::BitcoinExchange()" << std::endl;
    std::vector<std::pair<std::string, float> > inputInfo = getInputInfo(input);

    for (std::vector<std::pair<std::string, float> >::iterator it = inputInfo.begin(); it != inputInfo.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange::~BitcoinExchange()" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    // std::cout << "BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)" << std::endl;
    *this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    // std::cout << "BitcoinExchange::operator=(const BitcoinExchange &rhs)" << std::endl;
    if (this != &rhs)
    {
        m_prices = rhs.m_prices;
        // m_pricesList = rhs.m_pricesList;
    }
    return *this;
}

// int BitcoinExchange::maxProfit()
// {
//     int maxProfit = 0;
//     int minPrice = m_prices[0];
//     int maxPrice = m_prices[0];
//     for (int i = 0; i < (int)m_prices.size(); i++)
//     {
//         if (m_prices[i] < minPrice)
//         {
//             minPrice = m_prices[i];
//             maxPrice = m_prices[i];
//         }
//         if (m_prices[i] > maxPrice)
//         {
//             maxPrice = m_prices[i];
//         }
//         if (maxPrice - minPrice > maxProfit)
//         {
//             maxProfit = maxPrice - minPrice;
//         }
//     }
//     return maxProfit;
// }

// int BitcoinExchange::maxProfitList()
// {
//     int maxProfit = 0;
//     int minPrice = m_pricesList.front();
//     int maxPrice = m_pricesList.front();
//     for (int i = 0; i < m_pricesList.size(); i++)
//     {
//         if (m_pricesList.front() < minPrice)
//         {
//             minPrice = m_pricesList.front();
//             maxPrice = m_pricesList.front();
//         }
//         if (m_pricesList.front() > maxPrice)
//         {
//             maxPrice = m_pricesList.front();
//         }
//         if (maxPrice - minPrice > maxProfit)
//         {
//             maxProfit = maxPrice - minPrice;
//         }
//         m_pricesList.pop_front();
//     }
//     return maxProfit;
// }

int BitcoinExchange::getCurrentYear() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
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
    // int val = std::stoi(value);
    if (value < 0)
        return false;
    return true;
}

bool BitcoinExchange::validValueFormat(int value)
{
    // int val = std::stoi(value);
    if (value < 0 || value > 100)
        return false;
    return true;
}

// bool BitcoinExchange::validInput()
// {
//     return true;
// }

std::vector<std::pair<std::string, float> > BitcoinExchange::getCsvInfo(std::string file)
{
    std::vector<std::pair<std::string, float> > csvInfo;
    // std::ifstream csvFile(file.c_str()); c09/ex00/src/data.csv
    std::ifstream csvFile(file.c_str());
    if (!csvFile.good())
        std::cout << "File is not good" << std::endl;
    std::string line;
    std::string date;
    std::getline(csvFile, line); // skip the first line (date,exchange_rate)
    float value;
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        if (!validDateFormat(date))
        {
            throw std::invalid_argument("Invalid date format. The input string must be in the format YYYY-MM-DD.");
            exit(1);
        }
        if (!validPrice(value))
        {
                throw std::invalid_argument("Invalid value format. The input string must be in the format 0.0 - 100.0.");
                exit(1);
        }
        ss >> value;
        csvInfo.push_back(std::make_pair(date, value));
    }
    return csvInfo;
}

std::vector<std::pair<std::string, float> > BitcoinExchange::getInputInfo(std::string file)
{
    std::vector<std::pair<std::string, float> > csvInfo;
    std::ifstream csvFile(file.c_str());
    if (!csvFile.good())
        throw std::invalid_argument("Invalid file path or file is not good");

    std::string line;
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        float value;
        if (std::getline(ss, dateStr, '|'))
        {
            std::string date = trim(dateStr); // trim removes whitespace from the string
            if (!validDateFormat(date))
                throw std::invalid_argument("Invalid date format. The input string must be in the format YYYY-MM-DD.");
            
            if (ss >> value)
            {
                if (!validValueFormat(value))
                    throw std::invalid_argument("Invalid value format. The input value must be in the format 0.0 - 100.0.");
                
                csvInfo.push_back(std::make_pair(date, value));
            }
            else
                throw std::invalid_argument("Invalid input format. Expected <date> | <value>.");
        }
        else
            throw std::invalid_argument("Invalid input format. Expected <date> | <value>.");
    }
    return csvInfo;
}

std::string BitcoinExchange::trim(const std::string& str)
{
    std::string::size_type first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    std::string::size_type last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}