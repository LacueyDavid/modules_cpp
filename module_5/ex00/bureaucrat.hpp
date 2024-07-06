/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:58:46 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/06 16:36:25 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iosfwd>
#include <stdexcept>

class Bureaucrat
{
public:
	size_t getGrade() const; // si la methode modifie rien, const a la fin
	const std::string& getName() const;
	void upGrade();
	void downGrade();
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(const Bureaucrat& other);
	void swap(Bureaucrat& other);
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
	Bureaucrat &operator=(Bureaucrat other); // function membre car on
													// utilise this
	const std::string name;
	size_t grade;
	static const size_t highest_grade = 1;
	static const size_t lowest_grade = 150;
};

std::ostream& operator<<(std::ostream& ostr, const Bureaucrat& b);

#endif
