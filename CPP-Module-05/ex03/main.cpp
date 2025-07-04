/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:11:24 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/02 10:11:25 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main(void)
{
    std::cout << "\n=========== 1* Test ===========\n";
    try
    {
        AForm * list = new ShrubberyCreationForm("list");
        Bureaucrat police("Isaac", 137);
        Bureaucrat Pr("Pr", 1);

        Pr.signForm(*list);
        police.executeForm(*list);
        std::cout << *list << std::endl;
        delete list;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n=========== 2* Test ===========\n";
    try
    {
        AForm * phoneBook = new RobotomyRequestForm("book");
        Bureaucrat judge("Gonçalves", 45);
        Bureaucrat Professor("Pr", 72);

        Professor.signForm(*phoneBook);
        judge.executeForm(*phoneBook);
        std::cout << *phoneBook << std::endl;
        delete phoneBook;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n=========== 3* Test ===========\n";
    try
    {
        AForm * sentence = new PresidentialPardonForm("robber");
        Bureaucrat judge("Almeida", 3);
        Bureaucrat police("James", 5);

        std::cout << judge << std::endl << police << std::endl;
        judge.signForm(*sentence);
        police.executeForm(*sentence);
        std::cout << *sentence << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        AForm * sentence2 = new PresidentialPardonForm("robber");
        Bureaucrat judge2("Almeida", 50);
        Bureaucrat police2("James", 5);

        std::cout << judge2 << std::endl << police2 << std::endl;
        judge2.signForm(*sentence2);
        police2.executeForm(*sentence2);
        std::cout << *sentence2 << std::endl;
        delete sentence2;
        delete sentence;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n=========== 4* Test ===========\n";
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        (void)rrf;
        rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
        delete rrf;
        rrf = NULL;
        rrf = someRandomIntern.makeForm("Invalid Form name", "Bender");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}