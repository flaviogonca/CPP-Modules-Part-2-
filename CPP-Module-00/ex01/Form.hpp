/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:49:05 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/27 12:49:13 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        bool status;
        const std::string name;
        const short gradeToSign;
        const short gradeToExec;


    public:
        Form();
        ~Form();
        Form(std::string name, short gradeToSign, short gradeToExec);
        Form(const Form& original);
        Form& operator=(const Form& original);

        std::string getFormName() const;
        short getFormGradeToSign() const;
        short getFormGradeToExec() const;

        void beSigned(const Bureaucrat& original);

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

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif
