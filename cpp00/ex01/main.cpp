#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			phonebook.addContact();
		}
		else if (cmd == "SEARCH")
		{
			phonebook.searchContacts();
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
	}
	return (0);
}
