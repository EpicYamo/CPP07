/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:51:35 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 15:34:02 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

template <typename T>
static void	print_array(const std::string &label, const Array<T> &array);
static void	test_out_of_bounds(Array<int> &array, int index);
static int	subject_test(void);

int	main(void)
{
	Array<int>			empty;
	Array<int>			numbers(5);
	Array<std::string>	words(3);
	unsigned int		i;

	std::cout << "--- construction ---" << std::endl;
	print_array("empty", empty);
	print_array("numbers(5)", numbers);
	print_array("words(3)", words);
	i = 0;
	while (i < numbers.size())
	{
		numbers[i] = i * 10;
		i++;
	}
	words[0] = "hello";
	words[1] = "from";
	words[2] = "Array";
	print_array("numbers filled", numbers);
	print_array("words filled", words);

	std::cout << std::endl << "--- copy constructor ---" << std::endl;
	{
		Array<int>	copy(numbers);

		copy[0] = 999;
		print_array("original", numbers);
		print_array("copy", copy);
	}

	std::cout << std::endl << "--- assignment operator ---" << std::endl;
	{
		Array<int>	assigned(2);
		Array<int>	&same = assigned;

		assigned = numbers;
		numbers[1] = -1;
		print_array("original", numbers);
		print_array("assigned", assigned);
		assigned = same;
		print_array("self-assigned", assigned);
	}

	std::cout << std::endl << "--- out of bounds ---" << std::endl;
	test_out_of_bounds(numbers, 5);
	test_out_of_bounds(numbers, -2);
	test_out_of_bounds(empty, 0);

	std::cout << std::endl << "--- subject test (750 random values) ---"
		<< std::endl;
	if (subject_test() != 0)
		return (1);
	return (0);
}

template <typename T>
static void	print_array(const std::string &label, const Array<T> &array)
{
	unsigned int	i;

	std::cout << label << " (size " << array.size() << "): [";
	i = 0;
	while (i < array.size())
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << array[i];
		i++;
	}
	std::cout << "]" << std::endl;
}

static void	test_out_of_bounds(Array<int> &array, int index)
{
	try
	{
		array[index] = 42;
		std::cout << "index " << index << ": no exception (wrong)"
			<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "index " << index << ": " << e.what() << std::endl;
	}
}

static int	subject_test(void)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror;
	int			i;

	mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));
	i = 0;
	while (i < MAX_VAL)
	{
		mirror[i] = std::rand();
		numbers[i] = mirror[i];
		i++;
	}
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}
	i = 0;
	while (i < MAX_VAL)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return (1);
		}
		i++;
	}
	std::cout << "all " << MAX_VAL << " values survived copies" << std::endl;
	delete[] mirror;
	return (0);
}
