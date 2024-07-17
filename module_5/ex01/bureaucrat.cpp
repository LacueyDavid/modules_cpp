/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:25 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/16 22:59:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"
#include "bureaucrat.hpp"
#include <iostream>

size_t Bureaucrat::getGrade() const
{
	return grade;
}

const std::string& Bureaucrat::getName() const// pour la perf, ne pas faire une copy
										 // si on veut une copy local, call
										 // copy const
{
	return name;
}

void Bureaucrat::upGrade()
{
	if (grade == highest_grade)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::downGrade()
{
	if (grade == lowest_grade)
		throw GradeTooLowException();
	grade++;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat other)
{
	swap(other);
	return *this;
}

std::ostream& operator<<(std::ostream& ostr, const Bureaucrat& b)
{
	ostr << b.getName() << ", bureaucrat grade " << b.getGrade();
	return ostr;
}

Bureaucrat::Bureaucrat()
	: name("default")
	, grade(lowest_grade)
{}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, size_t grade)
	: name(name)
	, grade(grade)
{
	if (grade < highest_grade)
		throw GradeTooHighException();
	if (grade > lowest_grade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name)
	, grade(other.grade)
{}

void Bureaucrat::swap(__attribute__((unused)) Bureaucrat& other)
{
	// std::swap(name, other.name);
	// std::swap(grade, other.grade);
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	: std::domain_error("Grade too low.")
{}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: std::domain_error("Grade too high.")
{}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << "\n";
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << "\n";
	}
}
