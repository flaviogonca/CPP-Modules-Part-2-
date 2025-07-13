/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:16:02 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/12 17:17:14 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char *av[])
{
	Data *ptr;
	Data *tmp;
	uintptr_t integer = 0;

	ptr = new Data;
	ptr->value = 42;

	std::cout << "adress: " << ptr <<" value: " << ptr->value << std::endl;
	std::cout << "integer: " << integer << std::endl;
	std::cout << "================================================="<< std::endl;
	std::cout << "Serializing................"<< std::endl;
	integer = Serializer::serialize(ptr);
	std::cout << "Serialized: " << integer << std::endl;
	std::cout << "Deserializing................"<< std::endl;
	tmp = Serializer::deserialize(integer);
	std::cout << "Descerialized: " <<  std::endl;
	std::cout << "adress: " << tmp <<" value: " << tmp->value << std::endl;
	std::cout << "================================================="<< std::endl;
	delete ptr;
	return 0;
}
