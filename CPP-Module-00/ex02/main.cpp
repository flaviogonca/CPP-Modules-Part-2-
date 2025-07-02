/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:11:24 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/02 10:11:25 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        AForm * list = new ShrubberyCreationForm("list");
        Bureaucrat police("Isaac", 137);
        Bureaucrat Pr("Jlo", 1);

        Pr.signForm(*list);
        police.executeForm(*list);
        std::cout << *list << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}