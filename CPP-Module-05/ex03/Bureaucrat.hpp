/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:07:06 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:07:08 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        unsigned short grade;

    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, short grade);
        Bureaucrat(const Bureaucrat& original);
        Bureaucrat& operator=(const Bureaucrat& original);

        std::string getName() const;
        short getGrade() const;
        void increment();
        void decrement();

        void signForm(AForm &form);
        void executeForm(AForm const & form) const;

        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
    
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
