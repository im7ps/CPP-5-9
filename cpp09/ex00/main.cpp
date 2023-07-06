/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:57:58 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/06 09:43:34 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_argc(int argc)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc {filename.txt}\n";
        return 1;
    }
    return 0;
}

int check_file(std::ifstream& file)
{
    if (!file) 
    {
        std::cout << "Impossibile aprire il file.\n";
        return 1;
    }
    return 0;
}

void close_file(std::ifstream& file)
{
    file.close();
}

int check_first_line(std::ifstream& file, char div)
{
    std::string line;
    if (div == ',')
    {
        std::getline(file, line);
        return 0;
    }

    std::getline(file, line);
    if (line.empty() || !line.compare("date | value\n"))
    {
        std::cout << "First line should be: date | value" << std::endl;
        return 1;
    }
    return 0;
}

bool is_valid_date(std::string& dateStr)
{
    if (dateStr.length() != 10)
        return false;

    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr = dateStr.substr(8, 2);

    int year, month, day;
    if (yearStr.length() != 4 || monthStr.length() != 2 || dayStr.length() != 2)
        return false;

    try 
    {
        year = std::stoi(yearStr);
        month = std::stoi(monthStr);
        day = std::stoi(dayStr);
    } 
    catch (std::exception& e) 
    {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 2 && day > 29) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        return false;

    return true;
}

bool check_line(const std::string& line, std::string& date, double& value, char div)
{
    std::string modifiedLine = line;

    std::replace(modifiedLine.begin(), modifiedLine.end(), ',', ' ');
    std::istringstream iss(modifiedLine);
    if (!(iss >> date))
    {
        if (!is_valid_date(date))
        {
            return false;
        }
    }

    if (div == '|')
    {
        char    separator;

        iss >> separator;
        if (separator != div && separator)
        {
            return false;
        }    
    }

    std::string valueString;
    if (!(iss >> valueString))
    {
        valueString = "-1";
        return false;
    }

    value = std::stod(valueString);
    if (value < 0 || value > 2147483647)
    {
        return false;
    }
    return true;
}

int file_validator(std::ifstream& file, std::multimap<std::string, double>& mymap, char div)
{
    std::string line;
    std::string date;
    double value;

    if (check_first_line(file, div))
        return 1;
    while (std::getline(file, line))
    {
        if (line.compare("\n") && line.compare("\0"))
        {
            if (check_line(line, date, value, div))
            {
                mymap.insert(std::make_pair(date, value));
            }
            else
            {
                    value = -1;
                    mymap.insert(std::make_pair(date, value));
            }
        }
    }
    return 0;
}

void print_results(std::multimap<std::string, double> mymap, std::multimap<std::string, double> csvmap)
{
    std::multimap<std::string, double>::iterator myit;
    std::multimap<std::string, double>::iterator csvit;

    for (myit = mymap.begin(); myit != mymap.end(); ++myit)
    {
        std::string date = myit->first;
        double userValue = myit->second;

        csvit = csvmap.lower_bound(date);

        if (csvit != csvmap.end())
        {
            double exchangeRate = csvit->second;
            double result = userValue * exchangeRate;

            if (userValue < 0)
            {
                std::cout << "Error\n";
            }
            else
            {
                std::cout << date << " => " << userValue << " => " << result << std::endl;
            }
        }
        else
        {
            std::cout << "Date: " << date << ", Value: " << userValue << ", No corresponding data in CSV file\n";
        }
    }
}

int main(int argc, char* argv[])
{
    if (check_argc(argc))
        return 1;

    std::ifstream file(argv[1]);
    if (check_file(file))
        return 1;

    std::multimap<std::string, double> mymap;
    if (file_validator(file, mymap, '|'))
        return 1;

    std::ifstream file_csv("./data.csv");
    if (check_file(file_csv))
        return 1;

    std::multimap<std::string, double> csvmap;
    file_validator(file_csv, csvmap, ',');

    print_results(mymap, csvmap);

    close_file(file);
    close_file(file_csv);
    return 0;
}