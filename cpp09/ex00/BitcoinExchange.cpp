#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex>

int BitcoinExchange::loadDatabase() {
	std::ifstream inFile("data.csv");
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file data.csv" << std::endl;
		return -1;
	}
	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) {
		if (line.empty())
			continue;
		std::string date = line.substr(0, 10);
		float value = std::stof(line.substr(11, line.length() - 11));
		_data[date] = value;
	}
	return 0;
}

int BitcoinExchange::processInput(const std::string& filename) {
	if (loadDatabase() == -1)
		return -1;
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
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
			std::regex dateFormat("^\\d{4}-\\d{2}-\\d{2} | $");
			if (std::regex_match(date, dateFormat))
			{
				int year = std::stoi(date.substr(0, 4));
				int month = std::stoi(date.substr(5, 2));
				int day = std::stoi(date.substr(8, 2));
				if (month < 1 || month > 12 || day < 1) {
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
				}
				int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
				if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
					if (day > 29) {
						std::cout << "Error: bad input => " << line << std::endl;
						continue;
					}
				}
				else {
					if (day > days[month - 1]) {
						std::cout << "Error: bad input => " << line << std::endl;
						continue;
					}
				}
			}
			else {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			try {
				value = std::stof(line.substr(delim + 2));
				if (value < 0) {
					std::cout << "Error: not a positive number." << std::endl;
					continue;
				}
				if (value > 1000) {
					std::cout << "Error: too large a number." << std::endl;
					continue;
				}
			}
			catch (std::exception& e) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			float rate;
			std::string date = line.substr(0, delim - 1);
			std::map<std::string, float>::iterator it;
			it = _data.find(date);
			if (it != _data.end()) {
				rate = it->second;
			}
			else {
				it = _data.upper_bound(date);
				if (it == _data.begin()) {
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
				}
				--it;
				rate = it->second;
			}
			float result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
	return 0;
}
