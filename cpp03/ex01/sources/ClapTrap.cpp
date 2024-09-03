/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:38:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/03 18:15:07 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "ClapTrap Anonymous";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "\033[33m"
	<< "#ClapTrap :"
	<< "Default Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m"  << std::endl;

}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "\033[33m"
	<< "#ClapTrap :"
	<< " Constructor called" << std::endl
	<< this->getName() << " has been created!" <<  "\033[0m"  << std::endl;

}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[33m"
	<< "#ClapTrap :"
	<< " Deconstructor called" << std::endl
	<< this->getName() << " is dead!" <<  "\033[0m"  <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	//std::cout << "\033[34m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	//std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_name = copy.getName();
	this->_energyPoints = copy.getEnergypoint();
	this->_attackDamage = copy.getAttackdamage();
	this->_hitPoints = copy.getHitpoint();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "\033[33m"
	<< "#ClapTrap : " <<  "\033[0m"  << std::endl;
	if (validEnergypoints(*this) && validHitpoints(*this))
	{
		this->_energyPoints--;
		std::cout << "\033[33m"  << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << "\033[0m" ;
		std::cout << "\033[3m" << " [ Total of hit points left : " << this->_hitPoints << " ]" << "\033[0m" << std::endl;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << this->getName() << " took " << amount <<  " points of damage! ";
	std::cout << "\033[3m" << " [ Total of hit points left : " << this->_hitPoints << " ]" << "\033[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "\033[33m"
	<< "#ClapTrap : " <<  "\033[0m"  << std::endl;
	if (validEnergypoints(*this) && validHitpoints(*this))
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << this->getName() << " gained " << amount <<  " hit points! ";
		std::cout << "\033[3m" << " [ Total of hit points left : " << this->_hitPoints << " ]" << "\033[0m" << std::endl;
	}
}


/* --------------- Setters ---------------*/
void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitpoint(int points)
{
	this->_hitPoints = points;
}

void	ClapTrap::setEnergypoint(int points)
{
	this->_energyPoints = points;
}

void	ClapTrap::setAttackdamage(int damage)
{
	this->_attackDamage = damage;
}

/* --------------- Getters --------------- */
int	ClapTrap::getHitpoint() const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergypoint() const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackdamage() const
{
	return (this->_attackDamage);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}


/*Check if it has enough energy points */
bool	validEnergypoints(ClapTrap &claptrap)
{
	if (claptrap.getEnergypoint() <= 0)
	{
		std::cout << claptrap.getName() << " has no ernergy points left to attack" << std::endl;
		return (0);
	}
	else
		return (1);
}

bool	validHitpoints(ClapTrap &claptrap)
{
	if (claptrap.getHitpoint() <= 0)
	{
		std::cout << claptrap.getName() << " has no hit points left to repair" << std::endl;
		return (0);
	}
	else
		return (1);
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
	o << i.getName()
		<< ", hitPoints: " << i.getHitpoint()
		<< ", energyPoints: " << i.getEnergypoint()
		<< ", attackDamage: " << i.getAttackdamage()<< std::endl;

	return (o);
}
