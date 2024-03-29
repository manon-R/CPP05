#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

using std::string;

class RobotomyRequestForm : public AForm{

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const string& t);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm & operator= (const RobotomyRequestForm &other);

	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;
	string getTarget() const;

private:

	string target;
};

#endif