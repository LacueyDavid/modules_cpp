/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:25:20 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:41:05 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>

class Animal
{
public:
	std::string getType() const; //const a la fin == la method est const
								 // au debut == return un const
	virtual void makeSound() const;// =0 veut dire pas de comportement par default, il
							// faut la redefinir, =0 veut dire class abstraite
	virtual ~Animal();
protected:
	std::string type;
	Animal(const std::string& type);
private:
	Animal(const Animal& other);
	Animal operator=(const Animal& other);
};

// si une method est privé ou protected, elle ne peut pas etre appeler depuis
// lexterieur

#endif
