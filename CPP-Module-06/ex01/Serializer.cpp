/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:18:12 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/12 17:18:14 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& original) {}

Serializer& Serializer::operator=(const Serializer& original)
{
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast <uintptr_t> (ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast <Data*> (raw);
}
