#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int main (void){

	try{
		Bureaucrat b1("test1", 199);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	try{
		Bureaucrat b2("test2", -1);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	try{
		Bureaucrat b3("test3", 3);
	}
	catch (const std::exception& e)
	{
		cout << RED_BOLD << e.what() << RESET<< "\nInvalid grade (valid range [1;150])" << RESET << endl;
	}
	cout << endl;

	Bureaucrat b4("test4", 2);
	try{
		b4.increment();
	}
	catch (const std::exception& e){
		cout << RED_BOLD << e.what() << RESET << "\nNot possible to increment its grade" << endl;
	}
	try{
		b4.increment();
	}
	catch (const std::exception& e){
		cout << RED_BOLD << e.what() << RESET << "\nNot possible to increment its grade" << endl;
	}
	cout << endl;
	
	Bureaucrat b5("test5", 150);
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
