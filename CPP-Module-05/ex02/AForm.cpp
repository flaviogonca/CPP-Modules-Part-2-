/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:07:35 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:07:37 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): status(0), name("Default"), gradeToSign(2), gradeToExec(2) {}

AForm::~AForm() {}

AForm::AForm(std::string name, short gradeToSign, short gradeToExec): name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    status = false;
}

AForm::AForm(const AForm& original): name(original.name), gradeToSign(original.gradeToSign), gradeToExec(original.gradeToExec)
{
    status = original.status;
}

AForm& AForm::operator=(const AForm& original)
{
    if (&original != this)
        status = original.status;
    return *this;
}

std::string AForm::getFormName() const { return name; }

short AForm::getFormGradeToSign() const { return gradeToSign; }

short AForm::getFormGradeToExec() const { return gradeToExec; }

bool AForm::getFormStatus() const { return status; }

std::ostream& operator<<(std::ostream& os, AForm& obj)
{
    os << "Form Name: " << obj.getFormName()
    << "; Form Status: " << obj.getFormStatus() 
    << "; Grade to sign: " << obj.getFormGradeToSign()
    << "; Grade to Execute: " << obj.getFormGradeToExec();
    return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low.";
}

void AForm::beSigned(const Bureaucrat& original)
{
    if (original.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->status = true;
}
