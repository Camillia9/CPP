#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm  {
private:
	std::string _target;

protected:
	virtual void executeAction()const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm & other);
	RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
	~RobotomyRequestForm();
};

#endif