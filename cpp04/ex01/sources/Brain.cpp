/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:13:09 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/06 17:18:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[33m"
	<< "#Brain :"
	<< "Default Constructor called" << std::endl;
}

Brain::Brain(std::string type)
{
	std::cout << "\033[33m"
	<< "#Brain :"
	<< " Constructor called" <<  "\033[0m" << std::endl;

}

Brain::~Brain()
{
	std::cout << "\033[33m"
	<< "#Animal :"
	<< " Deconstructor called" <<  "\033[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	*this->_ideas = copy._ideas;
	return (*this);
}

void	Brain::setIdeas(std::string type)
{
	*this->_ideas = _ideas;
}

std::string	Brain::getIdeas() const
{
	return (this->_ideas);
}
