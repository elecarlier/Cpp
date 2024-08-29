/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:47 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/29 17:01:26 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	//std::cout << "\033[33m" << "Default constructor called" << "\033[0m" <<  std::endl;
}


Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
	//std::cout << "\033[33m" << "Int constructor called" << "\033[0m" <<  std::endl;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_bits));
	//std::cout << "\033[33m" << "Float constructor called" << "\033[0m" <<  std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "\033[32m" << "Desconstructor called" << "\033[0m"  << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>( this->getRawBits() ) / ( 1 << this->_bits ));
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->_bits);
}

/* --------------- Comparison operators --------------- */

bool	Fixed::operator<(Fixed const &fixed) const
{
	return( this->_value < fixed._value);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return( this->_value > fixed._value);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return( this->_value <= fixed._value);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return( this->_value >= fixed._value);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return( this->_value == fixed._value);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return( this->_value != fixed._value);
}

/* --------------- Arithmetic operators --------------- */
Fixed	Fixed::operator+(Fixed const &src)
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &src)
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &src)
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &src)
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

/* --------------- Increment/decrement operators --------------- */
Fixed	Fixed::operator++()
{
	++(this->_value);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp;

	temp = (*this);
	++(this->_value);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp;

	temp = (*this);
	--(this->_value);
	return (temp);
}

Fixed	Fixed::operator--()
{
	--(this->_value);
	return (*this);
}

/*--------------- min max ---------------*/

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}


Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}


const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}


std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
