/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:43:59 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/16 22:53:14 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
public:
	const std::string& getName() const;
	size_t getIsSigned() const;
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);
	void swap(Form& other);
	Form();
	~Form();
	Form(std::string name, size_t gradeToSign, size_t gradeToExecute);
	Form(const Form& other);
	class GradeTooHighException: public std::domain_error
	{
	public:
		GradeTooHighException();
	};
	class GradeTooLowException: public std::domain_error
	{
	public:
		GradeTooLowException();
	};
private:
	Form &operator=(Form other); // function membre car on
	const std::string name;
	bool isSigned;
	const size_t gradeToSign;
	const size_t gradeToExecute;
	static const size_t highest_grade = 1;
	static const size_t lowest_grade = 150;
};

std::ostream& operator<<(std::ostream& ostr, const Form& f); // pour print les
															 // infos

// TODO
//
// exception throw
//
// 
//

#endif
