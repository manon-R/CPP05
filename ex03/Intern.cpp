#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

Intern::Intern(){}

Intern::Intern(Intern const & other){
	*this = other;
}

Intern::~Intern(){}

Intern& Intern::operator=(Intern const & other){
	if (this == &other)
		return *this;
	return *this;
}


int Intern::isValidName(const string & name){
	string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (tab[i] == name)
			return i;
		i++;
	}
	return i;
}


AForm* Intern::makeForm(const string & name, const string & target){
	try{
		int index = isValidName(name);
		switch(index){
			case 0:
			{
				AForm *form = new ShrubberyCreationForm(target);
				cout << "Intern creates " << name << endl;
				return form;
			}
			case 1:
			{
				AForm *form = new RobotomyRequestForm(target);
				cout << "Intern creates " << name << endl;
				return form;
			}
			case 2:
			{
				AForm *form = new PresidentialPardonForm(target);
				cout << "Intern creates " << name << endl;
				return form;
			}
			default:
				throw InvalidFormNameException();
				break;
		}
	}
	catch (std::exception& e){
		cout << "Impossible to create this form :\n" <<  RED << e.what() << RESET << endl; 
	}
	return NULL;
}

const char *Intern::InvalidFormNameException::what() const throw(){
		return ("***** !!!!! Invalid Name !!!!! *****");
}