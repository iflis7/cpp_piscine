#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file)
{
    // std::cout << "BitcoinExchange::BitcoinExchange()" << std::endl;
    std::cout << "file: " << file << std::endl;
    std::vector<std::pair<std::string, float> > csvInfo = getCsvInfo(file);

    std::cout << "file1: " << file << std::endl;
    for (std::vector<std::pair<std::string, float> >::iterator it = csvInfo.begin(); it != csvInfo.end(); ++it)
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
        m_pricesList = rhs.m_pricesList;
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

// bool BitcoinExchange::validDateForamt()
// {
//     return true;
// }

// bool BitcoinExchange::validValueFormat()
// {
//     return true;
// }

// bool BitcoinExchange::validInput()
// {
//     return true;
// }

std::vector<std::pair<std::string, float> > BitcoinExchange::getCsvInfo(const std::string file)
{
    std::vector<std::pair<std::string, float> > csvInfo;
    std::ifstream csvFile(file.c_str());
    if (!csvFile.good())
        std::cout << "File is good" << std::endl;
    std::string line;
    std::string date;
    float value;
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> value;
        csvInfo.push_back(std::make_pair(date, value));
    }
    return csvInfo;
}
