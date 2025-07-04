/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:27:35 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/02 19:27:38 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    public:
        Intern();
        ~Intern();
        Intern(const Intern& original);
        Intern& operator=(const Intern& original);

        AForm* makeForm(std::string formName, std::string target);

        class InternException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
