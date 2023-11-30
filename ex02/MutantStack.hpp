#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		virtual ~MutantStack();

		MutantStack &operator=(MutantStack const &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

#endif