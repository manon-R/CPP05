#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
using std::string;

// Macros pour les couleurs
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[1;33m"
# define MAGENTA_B "\033[1;35m"
# define CYAN    "\033[36m"
# define RED_BOLD  "\033[1;31m"

class AForm{

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

	class NotSignedException : public std::exception{

	public:

		virtual const char *what() const throw();
	};

	AForm();
	AForm(const string name, unsigned int s, unsigned int e);
	AForm(const AForm& other);
	virtual ~AForm();

	string	getName() const;
	bool	getStatus()const;
	unsigned int getSignGrade()const;
	unsigned int getExecGrade()const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(Bureaucrat const & executor) const = 0;

protected:
	void checkExec(Bureaucrat const & b) const;

private:
	const string name;
	bool status;
	const unsigned int signGrade;
	const unsigned int execGrade;

	AForm& operator=(const AForm& other);
};

std::ostream& operator<<(std::ostream& out, const AForm& other);


#endif