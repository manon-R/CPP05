#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 72, 45), operationStatus(false){
}

RobotomyRequestForm::RobotomyRequestForm(const string& t):AForm("Robotomy Request", 72, 45), target(t), operationStatus(false){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	target = other.target;
	operationStatus = other.operationStatus;
	return *this;
}

string RobotomyRequestForm::getTarget() const{
	return target;
}

void RobotomyRequestForm::changeOperationStatus(){
	operationStatus = (operationStatus) ? false : true;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkExec(executor);
	if (operationStatus)
		cout << CYAN << target << " has been successfully robotomized" << RESET << endl;
	else
		cout << BLUE << target << "'s robotomy failed ..." << RESET << endl;
}