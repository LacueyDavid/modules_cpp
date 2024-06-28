/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:34:07 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:37:05 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class Wrongcat : public Wronganimal
{
public:
	Wrongcat();
	virtual ~Wrongcat();
	void makeSound() const;
	Wrongcat(const Wrongcat& other);
	Wrongcat &operator=(const Wrongcat& other);
};

#endif
