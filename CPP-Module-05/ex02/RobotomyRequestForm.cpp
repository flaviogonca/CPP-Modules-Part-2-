/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:08:27 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:08:29 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original): AForm(original), target(original.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
    if (&original != this)
    {
        target = original.target;
        AForm::operator=(original);
    }
    return *this;
}

const char* RobotomyRequestForm::RobotomyRequestException::what() const throw()
{
    return "Robotomy failed";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if ((executor.getGrade() > getFormGradeToExec()) || (getFormStatus() == false))
        throw RobotomyRequestException();
    std::cout << "Bzzzzzzzzzz............" << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << target << " robotomization has failed" << std::endl;

}
