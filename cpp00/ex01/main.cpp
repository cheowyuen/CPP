#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main(void)
{
	PhoneBook	book;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			book.addContact();
		}
		else if (cmd == "SEARCH")
		{
			book.searchContacts();
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
	}
	return (0);
}
