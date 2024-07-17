/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:25 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/17 00:02:59 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aform.hpp"
#include "bureaucrat.hpp"
#include <iostream>

size_t AForm::getGradeToSign() const
{
	return gradeToSign;
}

size_t AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

size_t AForm::getIsSigned() const
{
	return isSigned;
}

const std::string& AForm::getName() const// pour la perf, ne pas faire une copy
										 // si on veut une copy local, call
										 // copy const
{
	return name;
}

std::ostream& operator<<(std::ostream& ostr, const AForm& b)
{
	ostr << b.getName() << ", AForm gradeToExecute " << b.getGradeToExecute()
		<< " GradeToSign " << b.getGradeToSign() << " signed status "
		<< b.getIsSigned();
	return ostr;
}

AForm::AForm()
	: name("default") // initialiser dans le meme ordre que la declaration dans
					  // le hpp
	, isSigned(0)
	, gradeToSign(lowest_grade)
	, gradeToExecute(lowest_grade)
{}

AForm::~AForm(){}

AForm::AForm(std::string name, size_t gradeToSign, size_t gradeToExecute)
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

AForm::AForm(const AForm& other)
	: name(other.name)
	, isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign)
	, gradeToExecute(other.gradeToExecute)
{}

AForm::GradeTooLowException::GradeTooLowException()
	: std::domain_error("Grade too low.")
{}

AForm::GradeTooHighException::GradeTooHighException()
	: std::domain_error("Grade too high.")
{}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if (b.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	do_execute();
}
