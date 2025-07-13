/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:47:16 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/13 09:47:17 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    std::cout << "Creating an instance randomly ......" << std::endl;
    Base* base = generate();
    if (base)
    {
        std::cout << "Object of Type ";
        identify(base);
        std::cout << " Was created Sucessfully" << std::endl;
    }
    else
        std::cout << "Couldn´t create any instance" << std::endl;
    Base& ref = *base;
    std::cout << "Identifying type of referenced object ..." << std::endl;
    std::cout << "Object reference type: ";
    identify(ref);
    std::cout << std::endl;
    delete base;
    return 0;
}
