#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {}

void PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	static int	index = 0;

	while (true) 
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin >> std::ws, firstName);
		if (!firstName.empty())
		{
			_contacts[index].setFirstName(firstName);
			break ;
		}
	}
	while (true) 
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin >> std::ws, lastName);
		if (!lastName.empty())
		{
			_contacts[index].setLastName(lastName);
			break ;
		}
	}
	while (true) 
	{
		std::cout << "Enter nickname: "; 
		std::getline(std::cin >> std::ws, nickname);
		if (!nickname.empty())
		{
			_contacts[index].setNickname(nickname);
			break ;
		}
	}
	while (true) 
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin >> std::ws, phoneNumber);
		if (!phoneNumber.empty())
		{
			_contacts[index].setPhoneNumber(phoneNumber);
			break ;
		}
	}
	while (true) 
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin >> std::ws, darkestSecret);
		if (!darkestSecret.empty())
		{
			_contacts[index].setDarkestSecret(darkestSecret);
			break ;
		}
	}
	index = (index + 1) % 8;
	if (_count < 8)
		_count++;
}

std::string truncateName(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void PhoneBook::displayContact(int index) const
{ 
	std::cout << std::setw(10) << std::right << index + 1 << "|"
			  << std::setw(10) << std::right << truncateName(_contacts[index].getFirstName()) << "|"
		   	  << std::setw(10) << std::right << truncateName(_contacts[index].getLastName()) << "|"
			  << std::setw(10) << std::right << truncateName(_contacts[index].getNickname()) << std::endl;
}

void PhoneBook::displayFull(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContacts() const
{
	std::string	index;
	int			idx;

	if (_count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < _count; i++)
	{
		displayContact(i);
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	try
	{
		idx = std::stoi(index);
		if (idx < 1 || idx > _count)
			std::cout << "Invalid index" << std::endl;
		else
			displayFull(idx - 1);
	}
	catch (std::exception& e)
	{
		std::cout << "Invalid input" << std::endl;
	} 
}
