/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:32:41 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/29 19:29:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &copy);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	setName(std::string name);
		void	setHitpoint(int points);
		void	setEnergypoint(int points);
		void	setAttackdamage(int damage);

		int	getHitpoint() const;
		int	getEnergypoint() const;
		int getAttackdamage() const;
		std::string getName() const;

};
bool	validHitpoints(ClapTrap &claptrap);
bool	validEnergypoints(ClapTrap &claptrap);
std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif
