/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:51:31 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 15:34:07 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	private:
		T				*_elements;
		unsigned int	_size;

	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(const Array &other);
		~Array();

		T				&operator[](unsigned int index);
		const T			&operator[](unsigned int index) const;
		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

# include "Array.tpp"

#endif
