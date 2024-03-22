#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form(): signGrade(1), execGrade(1), status(false){}

Form::Form(const string n, unsigned int s, unsigned int e): name(n), signGrade(s), execGrade(e), status(false) {
	if (s > 150)
		throw GradeTooLowException();
	else if (s < 1)
		throw GradeTooHighException();
	if (e > 150)
		throw GradeTooLowException();
	else if (e < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), status(other.status){
}

Form &Form::operator= (const Form& other){
	throw ConstCantReassignException();
}

Form::~Form(){}

string Form::getName() const{
	return name;
}

bool Form::getStatus() const{
	return status;
}

const unsigned int Form::getSignGrade() const{
	return signGrade;
}

const unsigned int Form::getExecGrade() const{
	return execGrade;
}


void Form::beSigned(const Bureaucrat& b){
	if (status)
	{
		cout << RED <<  "Form " << name << " is already signed" << RESET << endl;
		return ;
	}
	else if (b.getGrade() > signGrade)
		throw Form::GradeTooHighException();
	else
		status = true;
}

std::ostream& operator<<(std::ostream& out, const Form& other){
	cout << MAGENTA << "**** Form " << other.getName() << " ****"<< RESET << endl;
	cout << "Status => ";
	if (other.getStatus())
		cout << MAGENTA << "SIGNED" << RESET << endl;
	else
		cout << MAGENTA <<"UNSIGNED" << RESET << endl;
	cout << "MIN grade required to sign => " << MAGENTA << other.getSignGrade() << RESET << endl;
	cout << "MIN grade required to execute => " << MAGENTA << other.getExecGrade() << RESET << endl;
}


const char *Form::GradeTooHighException::what() const throw(){
		return ("***** !!!!! GRADE TOO HIGH for this form !!!!! *****");
}

const char *Form::GradeTooLowException::what() const throw(){
		return ("***** !!!!! GRADE TOO LOW for this form !!!!! *****");
}

const char *Form::ConstCantReassignException::what() const throw(){
		return ("***** !!!!! IMPOSSIBLE TO REASSIGN CONST TYPE !!!!! *****");
}