/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:20:45 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 18:27:36 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"

int main() {

	Data* data = new Data();
	data->value = 42;

	uintptr_t serializedData = Serializer::serialize(data);
	std::cout << "Serialized pointer (uintptr_t): " << serializedData << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized pointer: " << deserializedData << std::endl;

	if (data == deserializedData)
	{
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "Value of Data after deserialization: " << deserializedData->value << std::endl;
	}
	else
	{
		std::cout << "Failed to serialize and deserialize." << std::endl;
	}

	delete data;

	return 0;
}
