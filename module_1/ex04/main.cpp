/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:02 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/30 23:46:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void my_sed(std::string& line, const std::string& from, const std::string& to)
{
	std::string tmp;
	std::string::size_type index = 0;
	std::string::size_type position = 0;

	while ((position = line.find(from, index)) != line.npos)
	{
		tmp.append(line, index, position - index);
		tmp.append(to);
		index = position + from.size();
	}
	tmp.append(line, index);
	line.swap(tmp);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;

	std::string filename = argv[1];
	std::string from = argv[2];
	std::string to = argv[3];
	std::string line;
	std::ifstream istrm(filename);
	std::ofstream ostrm(filename + ".replace");

	if (!istrm.is_open() || !ostrm.is_open())
		std::cerr << "failed to open " << filename << '\n';
	else
	{
		for (std::string line; std::getline(istrm, line);)
		{
			my_sed(line, from, to);
			ostrm << line << "\n";
		}
	}
}
