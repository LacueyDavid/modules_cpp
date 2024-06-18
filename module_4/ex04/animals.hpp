/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:25:20 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/13 23:27:30 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal
{
protected:
	std::string type;
	virtual void sound() = 0;// =0 veut dire pas de comportement par defaut, il
							// faut la redefinir
};
