/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:48 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/29 17:08:35 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed(); //default constructor
		~Fixed(); //destructor

		Fixed(const Fixed &copy);
		Fixed(const int);
		Fixed(const float);

		//overload operator
		Fixed &operator=(const Fixed &copy);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
