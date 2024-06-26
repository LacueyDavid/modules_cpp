/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:25:20 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:11:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Brain
{
public:
	std::string ideas[100];
};

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

class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog();
	virtual void makeSound() const; // si une instance de la class est const,
									// elle ne pourra appeler que ces methodes
									// const
private:
	Brain *brain;
};

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	virtual void makeSound() const;
private:
	Brain *brain;
};

// si une method est privé ou protected, elle ne peut pas etre appeler depuis
// lexterieur
