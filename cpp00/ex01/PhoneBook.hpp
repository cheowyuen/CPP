#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];

	public:
		void addContact();
		void searchContacts() const;
		void displayContact(int index) const;
};

#endif