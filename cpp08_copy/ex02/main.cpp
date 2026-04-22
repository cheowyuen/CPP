#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n===== List =====\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    	std::cout << *it << std::endl;

	std::cout << "\n===== Const =====\n";
	const MutantStack<int> cmstack(mstack);
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "\n===== Reverse =====\n";
	MutantStack<int> rmstack(mstack);
	MutantStack<int>::reverse_iterator rit = rmstack.rbegin();
	MutantStack<int>::reverse_iterator rite = rmstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\n===== Const Reverse  =====\n";
	const MutantStack<int> crmstack(mstack);
	MutantStack<int>::const_reverse_iterator crit = crmstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = crmstack.rend();
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	return 0;
}