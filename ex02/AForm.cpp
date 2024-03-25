#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm(): status(false), signGrade(1), execGrade(1){}

AForm::AForm(const string n, unsigned int s, unsigned int e): name(n), status(false), signGrade(s), execGrade(e){
	if (s > 150)
		throw GradeTooLowException();
	else if (s < 1)
		throw GradeTooHighException();
	if (e > 150)
		throw GradeTooLowException();
	else if (e < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other): name(other.name), status(other.status), signGrade(other.signGrade), execGrade(other.execGrade){
}

AForm &AForm::operator= (const AForm& other){
	throw ConstCantReassignException();
	if (this == &other)
		return *this;
	return *this;
}

AForm::~AForm(){}

string AForm::getName() const{
	return name;
}

bool AForm::getStatus() const{
	return status;
}

unsigned int AForm::getSignGrade() const{
	return signGrade;
}

unsigned int AForm::getExecGrade() const{
	return execGrade;
}


void AForm::beSigned(const Bureaucrat& b){
	if (status)
	{
		cout << b.getName() << " couldn't sign " << name << " because : " << RED <<  "AForm " << name << " is already signed" << RESET << endl;
		return ;
	}
	else if (b.getGrade() > signGrade)
	{
		cout << b.getName() << " couldn't sign " << name << " because : " << endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		status = true;
		cout << GREEN << b.getName() << " signed "  << name  << RESET << endl;
	}
}

void AForm::checkExec(Bureaucrat const & b) const{
	if (!status)
	{
		throw NotSignedException();
	}
	else if (b.getGrade() > execGrade)
	{
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& other){
	out << MAGENTA_B << "**** AForm " << other.getName() << " ****"<< RESET << endl;
	out << "Status => ";
	if (other.getStatus())
		out << MAGENTA_B << "SIGNED" << RESET << endl;
	else
		out << MAGENTA_B <<"UNSIGNED" << RESET << endl;
	out << "MIN grade required to sign => " << MAGENTA_B << other.getSignGrade() << RESET << endl;
	out << "MIN grade required to execute => " << MAGENTA_B << other.getExecGrade() << RESET << endl;
	return out;
}


const char *AForm::GradeTooHighException::what() const throw(){
		return ("***** !!!!! GRADE TOO HIGH (AForm exception) !!!!! *****");
}

const char *AForm::GradeTooLowException::what() const throw(){
		return ("***** !!!!! GRADE TOO LOW (AForm exception) !!!!! *****");
}

const char *AForm::ConstCantReassignException::what() const throw(){
		return ("***** !!!!! IMPOSSIBLE TO REASSIGN CONST TYPE !!!!! *****");
}

const char *AForm::NotSignedException::what() const throw(){
		return ("***** !!!!! FORM NOT SIGNED - CAN'T BE EXECUTED !!!!! *****");
}