/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:25 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/16 22:58:49 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"
#include "bureaucrat.hpp"
#include <iostream>

size_t Form::getGradeToSign() const
{
	return gradeToSign;
}

size_t Form::getGradeToExecute() const
{
	return gradeToExecute;
}

size_t Form::getIsSigned() const
{
	return isSigned;
}

const std::string& Form::getName() const// pour la perf, ne pas faire une copy
										 // si on veut une copy local, call
										 // copy const
{
	return name;
}


Form &Form::operator=(Form other)
{
	swap(other);
	return *this;
}

std::ostream& operator<<(std::ostream& ostr, const Form& b)
{
	ostr << b.getName() << ", Form gradeToExecute " << b.getGradeToExecute()
		<< " GradeToSign " << b.getGradeToSign() << " signed status "
		<< b.getIsSigned();
	return ostr;
}

Form::Form()
	: name("default") // initialiser dans le meme ordre que la declaration dans
					  // le hpp
	, isSigned(0)
	, gradeToSign(lowest_grade)
	, gradeToExecute(lowest_grade)
{}

Form::~Form(){}

Form::Form(std::string name, size_t gradeToSign, size_t gradeToExecute)
	: name(name)
	, isSigned(0)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
{
	if (gradeToSign < highest_grade || gradeToExecute < highest_grade)
		throw GradeTooHighException();
	if (gradeToSign > lowest_grade || gradeToExecute > lowest_grade)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name)
	, isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign)
	, gradeToExecute(other.gradeToExecute)
{}

void Form::swap(__attribute__((unused)) Form& other)
{
	// std::swap(name, other.name);
	// std::swap(grade, other.grade);
}

Form::GradeTooLowException::GradeTooLowException()
	: std::domain_error("Grade too low.")
{}

Form::GradeTooHighException::GradeTooHighException()
	: std::domain_error("Grade too high.")
{}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}
