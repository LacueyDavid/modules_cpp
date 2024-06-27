/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:34:45 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/27 11:31:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "animals.hpp"
#include "brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog();
	virtual void makeSound() const; // si une instance de la class est const,
									// elle ne pourra appeler que ces methodes
									// const
	Dog(const Dog& other);
	Dog &operator=(const Dog &other);
	void setIdea(const std::string &idea, int index);
	std::string	getIdea(int index);
private:
	Brain* brain;
};

#endif
