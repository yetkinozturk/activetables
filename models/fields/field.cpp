#include <string>
#include "field.h"


CharField::CharField (std::string const& name):Field(name,CHARFIELD) 
{
	
}


NumberField::NumberField (std::string const& name):Field(name,NUMBERFIELD)
{
}


DateField::DateField (std::string const& name, std::string date_format)
	:Field(name,DATEFIELD),date_format(date_format)
{
}

