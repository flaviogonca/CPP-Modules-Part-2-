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

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original): AForm(original), target(original.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
    if (&original != this)
    {
        target = original.target;
        AForm::operator=(original);
    }
    return *this;
}

const char* ShrubberyCreationForm::ShrubberyException::what() const throw()
{
    return "Form not signed or Grade to execute the form is higher than bureaucrat's grade";
}

const char* ShrubberyCreationForm::ShrubberyExceptionFileCreation::what() const throw()
{
    return "Failed to create the *_shrubbery file";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ((executor.getGrade() > getFormGradeToExec()) || (getFormStatus() == false))
        throw ShrubberyException();

    std::string filename = target;
    std::fstream file(filename.append("_shrubbery").c_str(), std::ios::out);

    if (!file)
        throw ShrubberyExceptionFileCreation();
    
    file << "     *    " << std::endl;
    file << "    ***   " << std::endl;
    file << "     *    " << std::endl;
    file << "    *f*   " << std::endl;
    file << "   **m**  " << std::endl;
    file << "     A    " << std::endl;
    file << "    *l*   " << std::endl;
    file << "   **u**  " << std::endl;
    file << "  +++n+++ " << std::endl;
    file << " ****g****" << std::endl;
    file << "*****o*****" << std::endl;
    file << "    |||   " << std::endl;
    file << "   \\|||/   " << std::endl;
    file << "    |0|   " << std::endl;
    file << "   \\|||/   " << std::endl;
    file << "    |||   ";
    file.close();
}
