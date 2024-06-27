/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:34:07 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:17:32 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "animals.hpp"

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	virtual void makeSound() const;
	Cat(const Cat& other);
	Cat &operator=(const Cat& other);
};

#endif
