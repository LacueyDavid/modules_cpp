/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:51:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 18:09:38 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materiasouce.hpp"

MateriaSource();
~MateriaSource();
MateriaSource(const MateriaSource &other);
MateriaSource &operator=(const MateriaSource &other);
void learnMateria(AMateria *materia);
AMateria *createMateria(const std::string &type);
