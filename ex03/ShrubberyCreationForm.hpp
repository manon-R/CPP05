#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

using std::string;

class ShrubberyCreationForm : public AForm{

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const string & t);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;
	string getTarget() const;

private:

	string target;

};

#endif
