#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
	unsigned int		size;
	std::vector<int>	vec;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& copy);
	~Span();
	Span& operator=(const Span& copy);

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	class FullException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class LongestSpanEx : public std::exception
	{
		virtual const char *what() const throw();
	};
	class ShortestSpanEx : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif