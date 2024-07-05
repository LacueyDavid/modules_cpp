/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:51:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/05 22:51:51 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materiasource.hpp"

MateriaSource::MateriaSource()
	: materias()
{}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; ++i)
		delete materias[i];
}

MateriaSource::MateriaSource(const MateriaSource &other)
	: materias()
{
    for (size_t i = 0; i < 4; ++i)
        materias[i] = other.materias[i]->clone();
}

MateriaSource &MateriaSource::operator=(MateriaSource other)
{
    swap(other);
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (materias[i] == 0)
        {
            materias[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{

    for (size_t i = 0; i < 4; ++i)
    {
        if (type == materias[i]->getType())
            return materias[i]->clone();
    }
    return 0;
}

void MateriaSource::swap(MateriaSource &other)
{
    std::swap(materias, other.materias);
}
