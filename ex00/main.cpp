#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int main (void){
	//Try to create a Bureaucrat with too high grade
	cout << CYAN << "***** Try to create a Bureaucrat with grade 199 *****" << RESET <<endl;
	try{
		Bureaucrat b1("test1", 199);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	//Try to create a Bureaucrat with too low / negative grade
	cout << CYAN << "***** Try to create a Bureaucrat with grade -1 *****" << RESET <<endl;
	try{
		Bureaucrat b2("test2", -1);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	//Try to create a Bureaucrat with valid grade
	cout << CYAN << "***** Create a Bureaucrat with valid grade 3 *****" << RESET <<endl;
	try{
		Bureaucrat b3("test3", 3);
		cout << b3 << endl;
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	//Create a valid Bureaucrat at grad 2 and increment its grade twice
	cout << CYAN << "***** Create a Bureaucrat with grade 2 and try to increment it twice *****" << RESET <<endl;
	Bureaucrat b4("test4", 2);
	cout << b4;
	try{
		b4.increment();
	}
	catch (const std::exception& e){
		cout << RED_BOLD << e.what() << RESET << "\nNot possible to increment its grade" << endl;
	}
	cout << b4 << endl;
	try{
		b4.increment();
	}
	catch (const std::exception& e){
		cout << RED_BOLD << e.what() << RESET << "\nNot possible to increment its grade" << endl;
	}
	cout << endl;
	

	//Create a Bureaucrat at grad 150 and try to decrement its grade
	cout << CYAN << "***** Create a Bureaucrat with grade 150 and try to decrement its grade *****" << RESET <<endl;
	Bureaucrat b5("test5", 150);
	cout << b5 << endl;
	try{
		b5.decrement();
	}
	catch (const std::exception& e){
		cout << RED_BOLD << e.what() << RESET << "\nNot possible to decrement its grade" << endl;
	}
	cout << endl;
	cout << b5 << endl;
	return 0;
}
