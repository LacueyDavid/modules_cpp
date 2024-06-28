/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:23:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/28 10:46:51 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "cat.hpp"
#include "dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " \n";
	std::cout << i->getType() << " \n";
	i->makeSound();
	j->makeSound();
	const Wronganimal* wa = new Wrongcat();
	wa->makeSound();
	delete(j);
	delete(i);
	delete(wa);

	const Animal* animals[20];
	for(size_t i = 0; i < 10; ++i)
		animals[i] = new Dog();
	for(size_t i = 10; i < 20; ++i)
		animals[i] = new Cat();
	for(size_t i = 0; i < 20; ++i)
		animals[i]->makeSound();

	Cat cat;
	cat.setIdea("oh oui j'aime le fromage", 4);
	std::cout << "cat: " << cat.getIdea(4) << "\n";

	Cat jojo = cat;
	std::cout << "jojo: " << jojo.getIdea(4) << "\n";

	Cat jaja(jojo);
	std::cout << "jaja: " << jaja.getIdea(4) << "\n";

	for(size_t i = 0; i < 20; ++i)
		delete(animals[i]);
	return 0;
	return 0;
}
