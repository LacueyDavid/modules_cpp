/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:23:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 13:02:50 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
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
	delete(j);
	delete(i);

	const Animal* animals[20];
	for(size_t i = 0; i < 10; ++i)
		animals[i] = new Dog();
	for(size_t i = 10; i < 20; ++i)
		animals[i] = new Cat();
	for(size_t i = 0; i < 20; ++i)
		animals[i]->makeSound();
	for(size_t i = 0; i < 20; ++i)
		delete(animals[i]);
	return 0;
}
