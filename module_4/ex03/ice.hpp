/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:20:44 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 18:11:36 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "amateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	virtual ~Ice();
	Ice &operator=(const Ice &other);
	Ice* clone() const;
	void use(ICharacter& target);
private:
};

#endif
