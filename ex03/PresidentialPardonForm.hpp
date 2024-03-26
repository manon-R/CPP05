#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

using std::string;

class PresidentialPardonForm : public AForm{

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const string& t);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm & operator= (const PresidentialPardonForm &other);

	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;
	string getTarget() const;

private:

	string target;

};

#endif