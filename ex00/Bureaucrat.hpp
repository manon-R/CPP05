#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

// Macros pour les couleurs
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RED_BOLD  "\033[1;31m"


using std::string;

class Bureaucrat{

class GradeTooHighException : public std::exception{

public:

	virtual const char *what() const throw(){
		return ("***** !!!!! GRADE TOO HIGH !!!!! *****");
	}
};

class GradeTooLowException : public std::exception{

public:

	virtual const char *what() const throw(){
		return ("***** !!!!! GRADE TOO LOW !!!!! *****");
	}
};

public:

	Bureaucrat();
	Bureaucrat(const string& n, int g);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat & operator= (const Bureaucrat &other);

	~Bureaucrat();

	unsigned int getGrade() const;
	const string getName() const;

	void increment();
	void decrement();

private:

	const string name;
	unsigned int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif