/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:31:36 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/25 12:31:40 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        unsigned short grade;

    public:
        Bureaucrat();
        ~Bureaucrat();

        const std::string& getName() const;
        const short& getGrade() const;
        void increment();
        void decrement();

    class GradeTooHighException: std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException: std::exception
    {
        public:
            const char* Bureaucrat::GradeTooLowException::what() const throw();
    };
    
};

#endif
