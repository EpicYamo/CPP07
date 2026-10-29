/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:46:16 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 11:48:43 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void	iter(T *array, const size_t length, F func)
{
	size_t	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

#endif
