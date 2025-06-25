/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:31:46 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/25 12:31:47 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

const short& Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increment()
{
    try
    {
        if ((this->grade - 1) < 1)
            throw ;
        this->grade--;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::decrement()
{
    try
    {
        if ((this->grade + 1) > 150)
            throw ;
        this->grade++;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    std::string msg = "Grade too High";

    return msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    std::string msg = "Grade too Low";

    return msg.c_str();
}