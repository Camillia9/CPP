#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class  Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

protected:
	void virtual executeAction()const = 0;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	void beSigned(Bureaucrat const &b);
	std::string getName()const;
	int getGradeToSign()const;
	int getGradeToExec()const;
	bool getIsSigned()const;
	std::string statut()const;
	void execute(Bureaucrat const & executor)const;

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
	class FormNotSignedException : public std::exception {
	public:
		const char* what()const throw();
	};
	
};
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif