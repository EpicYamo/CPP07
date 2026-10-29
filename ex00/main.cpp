/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 07:02:18 by aaycan            #+#    #+#             */
/*   Updated: 2026/10/29 08:02:57 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	int			a = 2;
	int			b = 3;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	float		e = 4.2f;
	float		f = 4.2f;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << std::endl << "equal values (e = f = 4.2f):" << std::endl;
	std::cout << "min returns f: " << (&::min(e, f) == &f) << std::endl;
	std::cout << "max returns f: " << (&::max(e, f) == &f) << std::endl;
	return (0);
}
