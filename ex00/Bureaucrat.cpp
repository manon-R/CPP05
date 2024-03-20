#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

Bureaucrat::Bureaucrat(): grade(150){}

Bureaucrat::Bureaucrat(const string& n, int g): name(n){
	if (g > 150)
		throw GradeTooLowException();
	else if (g < 1)
		throw GradeTooHighException();
	else
		grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	(string)name = other.name;
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

unsigned int Bureaucrat::getGrade() const{
	return grade;
}

const string Bureaucrat::getName() const{
	return name;
}

void Bureaucrat::increment(){
	if ( grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		cout << GREEN << getName() << "'s grade +1" << RESET << endl;
		grade--;
	}
}

void Bureaucrat::decrement(){
	if ( grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		cout << RED << getName() << "'s grade -1" << RESET << endl;
		grade++;
	}
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& other){
	return out << CYAN << other.getName() << ", bureaucrat grade " << other.getGrade() << endl;
}