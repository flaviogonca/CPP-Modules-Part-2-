/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:09:00 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:09:01 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original): AForm(original) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
    AForm::operator=(original);
    return *this;
}

const char* ShrubberyCreationForm::ShrubberyException::what() const throw()
{
    return "Form not signed or Grade to execute the form is higher than bureaucrat's grade";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ((executor.getGrade() > getFormGradeToExec()) || (getFormStatus() == false))
        throw ShrubberyException();
}
