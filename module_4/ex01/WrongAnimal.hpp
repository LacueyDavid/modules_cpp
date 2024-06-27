/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:25:20 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:41:30 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class Wronganimal
{
public:
	std::string getType() const; //const a la fin == la method est const
								 // au debut == return un const
	void makeSound() const;// =0 veut dire pas de comportement par default, il
							// faut la redefinir, =0 veut dire class abstraite
	virtual ~Wronganimal();
	Wronganimal();
	Wronganimal(const Wronganimal& other);
	Wronganimal &operator=(const Wronganimal& other);
protected:
	std::string type;
	Wronganimal(const std::string& type);
};

// si une method est privé ou protected, elle ne peut pas etre appeler depuis
// lexterieur

#endif
