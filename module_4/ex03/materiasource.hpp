/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasouce.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:51:07 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 18:07:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "imateriasource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(MateriaSource other);
	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(const std::string &type);
	void swap(MateriaSource& other);
private:
	AMateria *materias[4];
};

#endif
