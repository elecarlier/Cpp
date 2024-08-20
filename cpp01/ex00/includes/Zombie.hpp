/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:32:25 by ecarlier          #+#    #+#             */
/*   Updated: 2024/08/20 15:57:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>


class Zombie
{
	private:
		std::string	_name;
	public:

		Zombie(std::string name);
		~Zombie();
		void	announce(void);

};

Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

#endif
