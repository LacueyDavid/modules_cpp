/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:23:33 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:36:26 by dlacuey          ###   ########.fr       */
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
	return 0;
}
