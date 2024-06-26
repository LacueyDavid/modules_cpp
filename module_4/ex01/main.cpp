/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:23:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:19:27 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " \n";
	std::cout << i->getType() << " \n";
	i->makeSound();
	j->makeSound();
	delete(j);
	delete(i);

	const Animal* animals[50];
	for(size_t i = 0; i < 25; ++i)
		animals[i] = new Dog();
	for(size_t i = 25; i < 50; ++i)
		animals[i] = new Cat();
	for(size_t i = 0; i < 50; ++i)
		animals[i]->makeSound();
	for(size_t i = 0; i < 50; ++i)
		delete(animals[i]);
	return 0;
}
