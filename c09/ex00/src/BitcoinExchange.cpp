#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file, std::string input)
{
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
    if (value < 0)
        return false;
    return true;
}

bool BitcoinExchange::validValueFormat(float value, std::string date)
{
    if(value == std::string::npos)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return(false);
    }
    else if(value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return(false);
    }
    else if(value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return(false);
    }
    return(true);
}

void BitcoinExchange::printPairInfo(std::list<std::pair<std::string, float> > pair)
{
    for (std::list<std::pair<std::string, float> >::iterator it = pair.begin(); it != pair.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << std::endl;
}

std::string BitcoinExchange::trim(const std::string& str)
{
    std::string::size_type first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    std::string::size_type last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

// std::vector<std::pair<std::string, float> > BitcoinExchange::getCsvInfo(std::string file)
// {
//     std::vector<std::pair<std::string, float> > csvInfo;
//     std::ifstream csvFile(file.c_str());
//     if (!csvFile.good())
//         std::cout << "File is not good" << std::endl;
//     std::string line;
//     std::string date;
//     std::getline(csvFile, line); // skip the first line (date,exchange_rate)
//     float value;
//     while (std::getline(csvFile, line))
//     {
//         std::stringstream ss(line);
//         std::getline(ss, date, ',');
//         if (!validDateFormat(date))
//         {
//             throw std::invalid_argument("Invalid date format. The input string must be in the format YYYY-MM-DD.");
//             exit(1);
//         }
//         if (!validPrice(value))
//         {
//                 throw std::invalid_argument("Invalid value format. The input string must be in the format 0.0 - 100.0.");
//                 exit(1);
//         }
//         ss >> value;
//         csvInfo.push_back(std::make_pair(date, value));
//     }
//     return csvInfo;
// }

std::list<std::pair<std::string, float> > BitcoinExchange::getCsvInfo(std::string file)
{
    std::list<std::pair<std::string, float> > csvInfo;
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


// std::vector<std::pair<std::string, float> > BitcoinExchange::getInputInfo(std::string file)
// {
//     std::vector<std::pair<std::string, float> > csvInfo;
//     std::ifstream csvFile(file.c_str());
//     if (!csvFile.good())
//         throw std::invalid_argument("Invalid file path or file is not good");
//     std::string line;
//     while (std::getline(csvFile, line))
//     {
//         std::stringstream ss(line);
//         std::string dateStr;
//         float value;
//         if (std::getline(ss, dateStr, '|'))
//         {
//             // std::cout << "dateStr: " << dateStr << std::endl;
//             std::string date = trim(dateStr); // trim removes whitespace from the string
//             if (ss >> value && date != "date")
//                 csvInfo.push_back(std::make_pair(date, value));
//             else if(date != "date")
//                 csvInfo.push_back(std::make_pair(date, std::string::npos));;
//         }
//         else
//             throw std::invalid_argument("Invalid value format. Should be like: <date | value>");
//     }
//     return csvInfo;
// }


std::list<std::pair<std::string, float> > BitcoinExchange::getInputInfo(std::string file)
{
    std::list<std::pair<std::string, float> > csvInfo;
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
            // std::cout << "dateStr: " << dateStr << std::endl;
            std::string date = trim(dateStr); // trim removes whitespace from the string
            if (ss >> value && date != "date")
                csvInfo.push_back(std::make_pair(date, value));
            else if(date != "date")
                csvInfo.push_back(std::make_pair(date, std::string::npos));
        }
        else
            throw std::invalid_argument("Invalid value format. Should be like: <date | value>");
    }
    return csvInfo;
}



// void BitcoinExchange::run()
// {
//    for (std::vector<std::pair<std::string, float> >::iterator it = this->inputInfo.begin();
//         it != this->inputInfo.end(); ++it)
//     {
//         for (std::vector<std::pair<std::string, float> >::iterator itr = this->csvInfo.begin(); 
//                 itr != this->csvInfo.end(); ++itr)
//         {
//             if(!validValueFormat(it->second, it->first))
//                 break;
//             if (it->first == itr->first) //
//             {
//                 float val = it->second * itr->second;
//                 std::cout << it->first << "=> " << it->second << " = " << val << std::endl;
//             }
//         }
//     } 
// }


void BitcoinExchange::run()
{
    for (std::list<std::pair<std::string, float> >::iterator it = this->inputInfo.begin();
         it != this->inputInfo.end(); ++it)
    {
        for (std::list<std::pair<std::string, float> >::iterator itr = this->csvInfo.begin(); 
             itr != this->csvInfo.end(); ++itr)
        {
            if(!validValueFormat(it->second, it->first))
                break;
            if (it->first == itr->first) //
            {
                float val = it->second * itr->second;
                std::cout << it->first << "=> " << it->second << " = " << val << std::endl;
            }
        }
    } 
}
