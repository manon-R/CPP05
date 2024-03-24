#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form(): status(false), signGrade(1), execGrade(1){}

Form::Form(const string n, unsigned int s, unsigned int e): name(n), status(false), signGrade(s), execGrade(e){
	if (s > 150)
		throw GradeTooLowException();
	else if (s < 1)
		throw GradeTooHighException();
	if (e > 150)
		throw GradeTooLowException();
	else if (e < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other): name(other.name), status(other.status), signGrade(other.signGrade), execGrade(other.execGrade){
}

Form &Form::operator= (const Form& other){
	throw ConstCantReassignException();
	if (this == &other)
		return *this;
	return *this;
}

Form::~Form(){}

string Form::getName() const{
	return name;
}

bool Form::getStatus() const{
	return status;
}

unsigned int Form::getSignGrade() const{
	return signGrade;
}

unsigned int Form::getExecGrade() const{
	return execGrade;
}


void Form::beSigned(const Bureaucrat& b){
	if (status)
	{
		cout << b.getName() << " couldn't sign " << name << " because : " << RED <<  "Form " << name << " is already signed" << RESET << endl;
		return ;
	}
	else if (b.getGrade() > signGrade)
	{
		cout << b.getName() << " couldn't sign " << name << " because : " << endl;
		throw Form::GradeTooLowException();
	}
	else
	{
		status = true;
		cout << GREEN << b.getName() << " signed "  << name  << RESET << endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& other){
	out << MAGENTA_B << "**** Form " << other.getName() << " ****"<< RESET << endl;
	out << "Status => ";
	if (other.getStatus())
		out << MAGENTA_B << "SIGNED" << RESET << endl;
	else
		out << MAGENTA_B <<"UNSIGNED" << RESET << endl;
	out << "MIN grade required to sign => " << MAGENTA_B << other.getSignGrade() << RESET << endl;
	out << "MIN grade required to execute => " << MAGENTA_B << other.getExecGrade() << RESET << endl;
	return out;
}


const char *Form::GradeTooHighException::what() const throw(){
		return ("***** !!!!! GRADE TOO HIGH (FORM exception) !!!!! *****");
}

const char *Form::GradeTooLowException::what() const throw(){
		return ("***** !!!!! GRADE TOO LOW (FORM exception) !!!!! *****");
}

const char *Form::ConstCantReassignException::what() const throw(){
		return ("***** !!!!! IMPOSSIBLE TO REASSIGN CONST TYPE !!!!! *****");
}