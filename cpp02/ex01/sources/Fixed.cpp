/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:47 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/27 18:59:17 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" <<  std::endl;
}
Fixed::Fixed(const int value)
{
	// this->_value = value;
	std::cout << "\033[33m" << "Int constructor called" << "\033[0m" <<  std::endl;
}

Fixed::Fixed(const float value)
{
	// this->_value = value;
	std::cout << "\033[33m" << "Float constructor called" << "\033[0m" <<  std::endl;
}

Fixed::~Fixed()
{
	std::cout << "\033[32m" << "Desconstructor called" << "\033[0m"  << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	this->_value = copy.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;

	this->_value = copy.getRawBits();
	return *this;

}

int	Fixed::getRawBits( void ) const
{
	std::cout << "\033[36m" << "getRawBits member function called" << "\033[0m" <<  std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "\033[37m" << "setRawBits member function called" << "\033[0m" <<  std::endl;
	this->_value = raw;
}
