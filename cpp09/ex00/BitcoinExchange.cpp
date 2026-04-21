#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <exception>

int BitcoinExchange::loadDatabase() {
	std::ifstream inFile("data.csv");
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file.\n";
		return -1;
	}
	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) {
		if (line.empty())
			continue;
		size_t comma = line.find(',');
		std::string date = line.substr(0, comma);
		try {
			float value = std::stof(line.substr(comma + 1));
			_data[date] = value;
		}
		catch (const std::exception&) {
			std::cerr << "Error: invalid database value\n";
			return -1;
		}
	}
	return 0;
}

int BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file.\n";
		return -1;
	}
	std::string line;
	std::getline(inFile, line);
	float value;
	while (std::getline(inFile, line)) {
		if (line.empty())
			continue;
		size_t delim = line.find('|');
		if (delim != std::string::npos) {
			std::string date = line.substr(0, delim + 2);
			std::regex dateFormat("^\\d{4}-\\d{2}-\\d{2} \\| $");
			if (std::regex_match(date, dateFormat))
			{
				try {
					int year = std::stoi(date.substr(0, 4));
					int month = std::stoi(date.substr(5, 2));
					int day = std::stoi(date.substr(8, 2));
					if (month < 1 || month > 12 || day < 1) {
						std::cerr << "Error: bad input => " << line << "\n";
						continue;
					}
					int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
					if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
						if (day > 29) {
							std::cerr << "Error: bad input => " << line << "\n";
							continue;
						}
					}
					else {
						if (day > days[month - 1]) {
							std::cerr << "Error: bad input => " << line << "\n";
							continue;
						}
					}
				}
				catch (const std::exception&) {
					std::cerr << "Error: bad input => " << line << "\n";
					continue;
				}
			}
			else {
				std::cerr << "Error: bad input => " << line << "\n";
				continue;
			}
			try {
				value = std::stof(line.substr(delim + 2));
				if (value < 0) {
					std::cerr << "Error: not a positive number.\n";
					continue;
				}
				if (value > 1000) {
					std::cerr << "Error: too large a number.\n";
					continue;
				}
			}
			catch (const std::exception&) {
				std::cerr << "Error: bad input => " << line << "\n";
				continue;
			}
			float rate;
			date = line.substr(0, delim - 1);
			std::map<std::string, float>::iterator it;
			it = _data.find(date);
			if (it != _data.end()) {
				rate = it->second;
			}
			else {
				it = _data.upper_bound(date);
				if (it == _data.begin()) {
					std::cerr << "Error: bad input => " << line << "\n";
					continue;
				}
				--it;
				rate = it->second;
			}
			float result = value * rate;
			std::cout << date << " => " << value << " = " << result << "\n";
		}
		else {
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
	}
	return 0;
}
