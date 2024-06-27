/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:45:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/27 09:05:25 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain &operator=(const Brain &other);
	void setIdea(const std::string &idea, int index);
	std::string getIdea(int index);

private:
	std::string ideas[100];
};

#endif
