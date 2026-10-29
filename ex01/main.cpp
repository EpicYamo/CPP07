/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:46:19 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 11:49:08 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

template <typename T>
static void	print(const T &element);
template <typename T>
static void	increment(T &element);
static void	shout(std::string &element);

int	main(void)
{
	int					numbers[] = {0, 1, 2, 3, 4};
	const int			const_numbers[] = {10, 20, 30};
	double				decimals[] = {1.5, 2.15, 3.135};
	std::string			words[] = {"hi", "there", "iter"};
	const std::string	const_words[] = {"const", "strings"};

	std::cout << "int array            : ";
	iter(numbers, 5, print<int>);
	std::cout << std::endl << "after increment<int> : ";
	iter(numbers, 5, increment<int>);
	iter(numbers, 5, print<int>);
	std::cout << std::endl << "const int array      : ";
	iter(const_numbers, 3, print<int>);
	std::cout << std::endl << "double array         : ";
	iter(decimals, 3, increment<double>);
	iter(decimals, 3, print<double>);
	std::cout << std::endl << "string array         : ";
	iter(words, 3, shout);
	iter(words, 3, print<std::string>);
	std::cout << std::endl << "const string array   : ";
	iter(const_words, 2, print<std::string>);
	std::cout << std::endl << "NULL array           : ";
	iter(static_cast<int *>(NULL), 5, print<int>);
	std::cout << "(nothing printed)" << std::endl;
	return (0);
}

template <typename T>
static void	print(const T &element)
{
	std::cout << element << " ";
}

template <typename T>
static void	increment(T &element)
{
	element++;
}

static void	shout(std::string &element)
{
	size_t	i;

	i = 0;
	while (i < element.length())
	{
		element[i] = std::toupper(static_cast<unsigned char>(element[i]));
		i++;
	}
}
