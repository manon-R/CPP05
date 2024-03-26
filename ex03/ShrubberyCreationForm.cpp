#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::ofstream;
using std::cerr;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const string & t): AForm("Shrubbery Creation", 145, 137), target(t){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("Shrubbery Creation", 145, 137), target(other.target){
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other){
	target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

string ShrubberyCreationForm::getTarget() const{
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

	checkExec(executor);
	ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile){
		cerr << RED << "Error : Impossible to open this " << target << "_shrubbery outfile !" << RESET << endl;
		return ;
	}
	outfile << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

}