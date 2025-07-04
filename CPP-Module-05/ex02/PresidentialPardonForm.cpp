/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:08:05 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:08:06 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("Default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original): AForm(original), target(original.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
    if (&original != this)
    {
        target = original.target;
        AForm::operator=(original);
    }
    return *this;
}

const char* PresidentialPardonForm::PresidentialPardonException::what() const throw()
{
    return "Form not signed or Grade to execute the form is higher than bureaucrat's grade";
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if ((executor.getGrade() > getFormGradeToExec()) || (getFormStatus() == false))
        throw PresidentialPardonException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
