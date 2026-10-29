/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:51:24 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 15:34:14 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other)
	: _elements(new T[other._size]()), _size(other._size)
{
	unsigned int	i;

	i = 0;
	while (i < _size)
	{
		_elements[i] = other._elements[i];
		i++;
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	T				*new_elements;
	unsigned int	i;

	if (this == &other)
		return (*this);
	new_elements = new T[other._size]();
	i = 0;
	while (i < other._size)
	{
		new_elements[i] = other._elements[i];
		i++;
	}
	delete[] _elements;
	_elements = new_elements;
	_size = other._size;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (OutOfBoundsException());
	return (_elements[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (OutOfBoundsException());
	return (_elements[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("Array: index out of bounds");
}

#endif
