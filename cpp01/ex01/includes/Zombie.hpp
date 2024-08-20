/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:10:27 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 18:10:05 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>


class Zombie
{
	private:
		std::string	_name;

	public:

		Zombie();
		~Zombie();

		void	setName(const std::string &name);
		void	announce(void);

};



Zombie* zombieHorde( int N, std::string name );

#endif
