#include "Account.hpp"
#include <iostream>
int Account::_nbAccounts = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
}

void	Account::displayStatus( void ) const
{
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}