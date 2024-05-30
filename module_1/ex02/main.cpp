/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:35:21 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/29 21:09:37 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << &str << "\n";
	std::cout << ptr << "\n";
	std::cout << &ref << "\n";

	std::cout << str << "\n";
	std::cout << *ptr << "\n";
	std::cout << ref << "\n";
}
