/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:49:18 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/27 12:49:19 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Default"), gradeToSign(2), gradeToExec(2) {}

Form::~Form() {}

Form::Form(std::string name, short gradeToSign, short gradeToExec): name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    status = false;
}

Form::Form(const Form& original): name(original.name), gradeToSign(original.gradeToSign), gradeToExec(original.gradeToExec)
{
    status = original.status;
}

Form& Form::operator=(const Form& original)
{
    if (&original != this)
        status = original.status;
    return *this;
}

std::string Form::getFormName() const { return name; }

short Form::getFormGradeToSign() const { return gradeToSign; }

short Form::getFormGradeToExec() const { return gradeToExec; }

std::ostream& operator<<(std::ostream& os, Form obj)
{
    os << "Form name: " << obj.getFormName() << " Grade to sign: " << obj.getFormGradeToSign() << " Grade to Execute: " << obj.getFormGradeToExec();
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too High. Valid grade range 1-150";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low. Valid grade range 1-150";
}

void Form::beSigned(const Bureaucrat& original)
{
    if (original.getGrade() <= this->gradeToSign)
        this->status = true;
    throw GradeTooLowException();
}
