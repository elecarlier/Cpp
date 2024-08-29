/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:48 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/29 16:50:54 by ecarlier         ###   ########.fr       */
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
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);

		Fixed(const int);
		Fixed(const float);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		/* Comparison operators */
		bool	operator<(Fixed const &fixed) const;
		bool	operator>(Fixed const &fixed) const;
		bool	operator<=(Fixed const &fixed) const;
		bool	operator>=(Fixed const &fixed) const;
		bool	operator==(Fixed const &fixed) const;
		bool	operator!=(Fixed const &fixed) const;

		/* Arithmetic operators */
		Fixed	operator+(Fixed const &fixed);
		Fixed	operator-(Fixed const &fixed);
		Fixed	operator*(Fixed const &fixed);
		Fixed	operator/(Fixed const &fixed);


		/* Increment/decrement operators */
		Fixed	operator++(int);
		Fixed	operator++();
		Fixed	operator--(int);
		Fixed	operator--();

		Fixed &operator=(const Fixed &copy);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
