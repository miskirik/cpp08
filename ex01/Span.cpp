#include "Span.hpp"

Span::Span(unsigned int n)
{
	this->size = n;
	this->vec = std::vector<int>();
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{}

Span&	Span::operator=(const Span& copy)
{
	this->size = copy.size;
	this->vec = copy.vec;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->vec.size() == this->size)
		throw FullException();
	this->vec.push_back(n);
}

int	Span::shortestSpan()
{
	if(this->vec.size() == 0 || this->vec.size() == 1)
		throw ShortestSpanEx();
	std::vector<int>::iterator v;
	v = this->vec.begin();

	std::sort(this->vec.begin(), this->vec.end());
	int min = this->vec[1] - this->vec[0];
	for (unsigned int i = 0; i < this->vec.size() - 1; i++)
	{
		if (this->vec[i + 1] - this->vec[i] < min)
			min = this->vec[i + 1] - this->vec[i];
	}
	return (min);
}

int	Span::longestSpan()
{
	if(this->vec.size() == 0 || this->vec.size() == 1)
		throw LongestSpanEx();

	int min;
	int max;
	std::sort(this->vec.begin(), this->vec.end());
	min = this->vec[0];
	max = this->vec[this->vec.size() - 1];
	return (max - min);
}

Span::Span()
{
	this->size = 0;
	this->vec = std::vector<int>();
}

const char * Span::FullException::what() const throw()
{
	return ("Span is full");
}
const char *Span::LongestSpanEx::what() const throw()
{
	return ("Longest span is not found");
}
const char *Span::ShortestSpanEx::what() const throw()
{
	return ("Shortest span is not found");
}