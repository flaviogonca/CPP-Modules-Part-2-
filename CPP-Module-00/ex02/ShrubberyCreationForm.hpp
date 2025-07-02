/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:08:55 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:08:56 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);

        void execute(Bureaucrat const & executor) const;

        class ShrubberyException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class ShrubberyExceptionFileCreation: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif