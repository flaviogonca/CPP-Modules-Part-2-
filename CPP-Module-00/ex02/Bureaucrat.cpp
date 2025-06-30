/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:07:14 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:07:20 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("Default"), grade(1)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, short grade): name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original): name(original.name), grade(original.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
    if (&original != this)
    {
        this->grade = original.getGrade();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

short Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increment()
{
    if ((this->grade - 1) < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrement()
{
    if ((this->grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High. The grade range is 1-150";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low. The grade range is 1-150";
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t signed " << form.getFormName() << " because ";
        std::cerr << e.what() << std::endl;
    }
}

