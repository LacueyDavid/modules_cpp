/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:43:59 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/06 16:56:35 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "bureaucrat.hpp"

class Form
{
public:
	const std::string& getName() const;
	size_t getGrade() const;
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);
private:
	const std::string name;
	bool isSigned;
	const size_t gradeToSign;
	const size_t gradeToExecute;
};

std::ostream& operator<<(std::ostream& ostr, const Form& f); // pour print les
															 // infos

// TODO
//
// exception throw
//
// 
