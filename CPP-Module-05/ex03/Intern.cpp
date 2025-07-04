/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:27:42 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/02 19:27:43 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& original) { *this = original; }

Intern& Intern::operator=(const Intern& original)
{
    (void)original;

    return *this;
}

const char* Intern::InternException::what() const throw()
{
    return "The Form Name given does not exist in the list.";
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* result = NULL;

    std::string formName[3] = {
        "Shrubbery Creation",
        "robotomy request",
        "Presidential Pardon"
    };

    size_t i;
    for (i = 0; i < 3; i++)
        if (formName[i] == name)
            break ;
    switch (i)
    {
        case 0:
            result = new ShrubberyCreationForm(target);
            break;
        case 1:
            result = new RobotomyRequestForm(target);
            break;
        case 2:
            result = new PresidentialPardonForm(target);
            break;
        default:
            throw InternException();
    }
    std::cout << "Intern creates " << name << " Form" << std::endl;
    return result;
}
