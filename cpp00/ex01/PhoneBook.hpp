#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_count;

	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
		void displayContact(int index) const;
		void displayFull(int index) const;
};

#endif