#include "Intern.hpp"

using std::cout;
using std::endl;

int main(void){

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	cout << *rrf << endl;

	AForm* test1;
	test1 = someRandomIntern.makeForm("test", "Bender");
	if (test1)
		cout << endl;
	cout << endl;

	AForm* test2;
	test2 = someRandomIntern.makeForm("shrubbery creation", "garden");
	cout << *test2 << endl;

	delete rrf;
	delete test2;
}