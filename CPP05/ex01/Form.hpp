#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class  Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	void beSigned(Bureaucrat const &b);
	std::string getName()const;
	int getGradeToSign()const;
	bool getIsSigned()const;
	std::string statut()const;

	class GradeTooHighException : public std::exception  {
	public:
			const char* what()const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
			const char* what()const throw();
	};
	class FormAlreadySignedException : public std::exception {
	public:
			const char* what()const throw();
	};
	
};
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif