/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:48 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/27 16:53:52 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed(); //default constructor
		~Fixed(); //destructor
		Fixed(const Fixed &copy); //copy constructor
		Fixed &operator=(const Fixed &copy); //overload operator

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
