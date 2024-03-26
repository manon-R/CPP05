#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

using std::string;

class Intern{

public:
	
	class InvalidFormNameException : public std::exception{

	public:

		virtual const char *what() const throw();
	};

	Intern();
	Intern(Intern const & other);
	~Intern();

	Intern &operator=(Intern const & other);

	AForm* makeForm(const string & name, const string & target);

private:

	int isValidName(const string & name);

};

# endif