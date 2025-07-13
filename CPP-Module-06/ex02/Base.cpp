/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:47:24 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/13 09:47:25 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base * generate(void)
{
    std::srand(std::time(NULL));
    int num = std::rand() % 3 + 1;

    if (num == 1)
        return new A;
    else if (num == 2)
        return new B;
    else if (num == 3)
        return new C;
    std::cout << "Couldn't Create any instance of A, B and C type" << std::endl;
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast <A*> (p))
        std::cout << "A";
    else if (dynamic_cast <B*> (p))
        std::cout << "B";
    else if (dynamic_cast <C*> (p))
        std::cout << "C";
    else
        std::cout << "Type not found";
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A";
        return;
    }
    catch (const std::exception &)
    {
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B";
        return;
    }
    catch (const std::exception &)
    {
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C";
        return;
    }
    catch (const std::exception &)
    {
    }
    std::cout << "Type not found";
}
