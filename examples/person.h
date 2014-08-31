#ifndef __PERSON__H_
#define __PERSON__H_

#include "models/fields/field.h"
#include "models/model.h"

class Person : public Model
{
private:
	Field id;
	Field username; 
    Field password;
    Field name;
    Field lastname;
	Field job;
public:
	Person();
};


#endif

