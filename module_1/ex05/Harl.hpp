/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:51:16 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/31 00:27:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>


class Harl
{
public:
	Harl();
	void complain(std::string level);
private:
	typedef void (Harl::*memfun)();
	std::pair<std::string, memfun> functions[4];
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
