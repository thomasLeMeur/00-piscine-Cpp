#include <iostream>
#include <list>
#include "mutantstack.hpp"

int main()
{
	{
		std::cout << "Work on list : " << std::endl;

		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;

		std::cout << "Print the list : " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl;
	}

	{
		std::cout << "Work on MutantStack : " << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Print the MutantStack : " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl << "Copy it into stack and print the new stack in popping it" << std::endl;

		std::stack<int> s(mstack);
		while (!s.empty())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}


	return 0;
}
