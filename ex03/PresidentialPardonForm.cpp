#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(const string& t):AForm("Presidential Pardon", 25, 5), target(t){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	target = other.target;
	return *this;
}

string PresidentialPardonForm::getTarget() const{
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	checkExec(executor);
	cout << MAGENTA_B << target << " has been pardoned by Zaphod Beeblebrox" << RESET << endl;
}