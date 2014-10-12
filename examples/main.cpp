#include <iostream>
#include <string>
#include "examples/person.h"

int main () 
{	
    std::cout<<"model demo"<<std::endl;

	Person *p1 = new Person();
	delete p1;


	return 0;
}
