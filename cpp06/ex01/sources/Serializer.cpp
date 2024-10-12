/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:50:10 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 18:19:10 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
	//std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

Serializer::~Serializer()
{
	//std::cout << "\033[32m" << "Destructor called" << "\033[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	if (this != &copy)
		*this = copy;
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	return *this;
}

/*takes a pointer and converts it to the unsigned integer type uintptr_t.*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
/*takes an unsigned integer parameter and converts it to a pointer to Data.*/
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
