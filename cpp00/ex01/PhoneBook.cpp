#include "PhoneBook.hpp"

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
	std::cout << std::setw(10) << std::right << index << "|"
			  << std::setw(10) << std::right << truncateName(_contacts[index].getFirstName()) << "|"
		   	  << std::setw(10) << std::right << truncateName(_contacts[index].getLastName()) << "|"
			  << std::setw(10) << std::right << truncateName(_contacts[index].getNickname()) << std::endl;
}

// void Contact::displayFull() const
// {
// 	std::cout << "First Name: " << firstName << std::endl;
// 	std::cout << "Last Name: " << lastName << std::endl;
// 	std::cout << "Nickname: " << nickname << std::endl;
// 	std::cout << "Phone Number: " << phoneNumber << std::endl;
// 	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
// }

void PhoneBook::searchContacts() const
{
	for (int i = 0; i < 8; i++)
	{
		displayContact(i);
	}
}
