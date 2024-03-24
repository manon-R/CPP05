#include "Form.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void){
// Try to create a Form with too high grade
	cout << CYAN << "***** Try to create a Form with grade 199 to be signed *****" << RESET <<endl;
	try{
		Form f1("test1", 199, 10);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	//Try to create a Form with too low / negative grade
	cout << CYAN << "***** Try to create a Form with grade to be executed 0 *****" << RESET <<endl;
	try{
		Form f2("test2", 10, 0);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

    //Try to create a Form with valid grade
	cout << CYAN << "***** Create a Form with grade 10 to be signed *****" << RESET <<endl;
	try{
		Form f3("Form3", 10, 5);
		cout << f3 << endl;
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
    Form f3("Form3", 10, 5);
	cout << endl;

	//Try to create a Bureaucrat with valid grade
	cout << CYAN << "***** Create a Bureaucrat with grade 130 *****" << RESET <<endl;
    Bureaucrat b1("Bureaucrat1", 130);
    cout << b1 << endl;
	cout << endl;

    //Try to create a Bureaucrat with valid grade
	cout << CYAN << "***** Create another Bureaucrat with grade 3 *****" << RESET <<endl;
    Bureaucrat b2("Bureaucrat2", 3);
    cout << b2 << endl;
	cout << endl;

     //Try to create a Bureaucrat with valid grade
	cout << CYAN << "***** Create another Bureaucrat with grade 10 *****" << RESET <<endl;
    Bureaucrat b3("Bureaucrat3", 10);
    cout << b3 << endl;
	cout << endl;

    //Now each Bureaucrat will try to sign the form
    cout << CYAN << "***** Now each Bureaucrat will try to sign the form *****" << RESET <<endl;
	try{
		b1.signForm(f3);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET << endl;
	}
	cout << endl;
    cout << f3 << endl;

    try{
		b2.signForm(f3);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET << endl;
	}
	cout << endl;
    cout << f3 << endl;

    try{
		b3.signForm(f3);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET << endl;
	}
	cout << endl;
    cout << f3 << endl;

	return 0;
}
