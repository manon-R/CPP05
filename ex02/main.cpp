#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;


int main(void){

cout << CYAN << "***** Create a ShrubberyCreationForm with target home *****" << RESET <<endl;
AForm *f1 = new ShrubberyCreationForm("home");
cout << *f1 << endl;
cout << endl;

cout << CYAN << "***** Create a RobotomyRequestForm with target Robot *****" << RESET <<endl;
AForm *f2 = new RobotomyRequestForm("Robot");
cout << *f2 << endl;
cout << endl;


cout << CYAN << "***** Create a PresidentialPardonForm with target Grinch *****" << RESET <<endl;
AForm *f3 = new PresidentialPardonForm("Grinch");
cout << *f3 << endl;
cout << endl;

cout << CYAN << "***** Create 3 different Bureaucrats *****" << RESET << endl;
Bureaucrat b1("B1", 5);
cout << b1 << endl;
Bureaucrat b2("B2", 42);
cout << b2 << endl;
Bureaucrat b3("B3", 135);
cout << b3 << endl;


cout << CYAN << "***** B1 try to execute an unsigned form *****" << RESET << endl;
b1.executeForm(*f1);
cout << endl;

cout << CYAN << "***** B1 sign f3 *****" << RESET << endl;
b1.signForm(*f3);
cout << endl;
cout << CYAN << "***** B3 try to execute f3 (but grade required is 5) *****" << RESET << endl;
b3.executeForm(*f3);
cout << endl;

cout << CYAN << "***** B3 sign f1 and execute it *****" << RESET << endl;
b3.signForm(*f1);
cout << endl;
b3.executeForm(*f1);
cout << endl;

cout << CYAN << "***** B2 sign f2 and execute it *****" << RESET << endl;
b2.signForm(*f2);
cout << endl;
b2.executeForm(*f2);
cout << endl;

cout << CYAN << "***** and now B1 execute f2 *****" << RESET << endl;
b1.executeForm(*f2);
cout << endl;

cout << CYAN << "***** Finally B1 execute f3 *****" << RESET << endl;
b1.executeForm(*f3);
cout << endl;

delete f1;
delete f2;
delete f3;
}