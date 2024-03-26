#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	if (grade == 1)
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

void Bureaucrat::signForm(AForm& f){
		f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		cout << name << " can't execute this form :\n" << RED_BOLD << e.what()<< RESET << endl;
		return ;
	}
	cout << GREEN << name << " executed " << form.getName() <<  RESET << endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
		return ("***** !!!!! GRADE TOO HIGH !!!!! *****");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
		return ("***** !!!!! GRADE TOO LOW !!!!! *****");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other){
	return out << YELLOW << other.getName() << ", bureaucrat grade " << other.getGrade() << RESET << endl;
}