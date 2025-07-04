/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:15:12 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/30 13:15:13 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        bool status;
        const std::string name;
        const short gradeToSign;
        const short gradeToExec;


    public:
        AForm();
        virtual ~AForm();
        AForm(std::string name, short gradeToSign, short gradeToExec);
        AForm(const AForm& original);
        AForm& operator=(const AForm& original);

        std::string getFormName() const;
        short getFormGradeToSign() const;
        short getFormGradeToExec() const;
        bool getFormStatus() const;

        void beSigned(const Bureaucrat& original);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, AForm& obj);

#endif
