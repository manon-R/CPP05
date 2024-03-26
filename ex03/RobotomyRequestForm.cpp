#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(const string& t):AForm("Robotomy Request", 72, 45), target(t){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("Robotomy Request", 72, 45), target(other.target){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	target = other.target;
	return *this;
}

string RobotomyRequestForm::getTarget() const{
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkExec(executor);
	int random_number = std::rand();
	bool status = (random_number % 2 == 0) ? true : false; 
	if (status)
		cout << YELLOW << target << " has been successfully robotomized" << RESET << endl;
	else
		cout << BLUE << target << "'s robotomy failed ..." << RESET << endl;
}