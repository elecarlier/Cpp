/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:13:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/09/06 17:15:21 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(std::string type);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		 ~Brain();

		 void	setIdeas(std::string type);
		std::string		getIdeas() const;
};

#endif
