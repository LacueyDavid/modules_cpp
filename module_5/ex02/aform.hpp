/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:43:59 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/17 00:02:41 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	const std::string& getName() const;
	size_t getIsSigned() const;
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);
	void swap(AForm& other);
	AForm();
	virtual ~AForm();
	AForm(std::string name, size_t gradeToSign, size_t gradeToExecute);
	AForm(const AForm& other);

	void execute(const Bureaucrat& b) const;

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
	virtual void do_execute() const = 0;
	const std::string name;
	bool isSigned;
	const size_t gradeToSign;
	const size_t gradeToExecute;
	static const size_t highest_grade = 1;
	static const size_t lowest_grade = 150;
};

std::ostream& operator<<(std::ostream& ostr, const AForm& f); // pour print les
															 // infos

// TODO
//
// exception throw
//
// 
//

#endif
