#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
using std::string;

// Macros pour les couleurs
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[36m"
# define RED_BOLD  "\033[1;31m"

class Form{

public:

class GradeTooHighException : public std::exception{

public:

	virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception{

public:

	virtual const char *what() const throw();
};

class ConstCantReassignException : public std::exception{

public:

	virtual const char *what() const throw();
};

	Form();
	Form(const string name, unsigned int s, unsigned int e);
	Form(const Form& other);
	~Form();

	string	getName() const;
	bool	getStatus()const;
	const unsigned int getSignGrade()const;
	const unsigned int getExecGrade()const;

	void beSigned(const Bureaucrat& b);

private:
	const string name;
	bool status;
	const unsigned int signGrade;
	const unsigned int execGrade;

	Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& out, const Form& other);


#endif