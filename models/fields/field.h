#ifndef __CUSTOM_FIELD_H__
#define __CUSTOM_FIELD_H__

#include "basefield.h"

class CharField : public Field {

private:
public:
    CharField(std::string const& name);
};


class NumberField : public Field {

private:
public:
    NumberField(std::string const& name);
};

class DateField : public Field {

private:
	std::string date_format;
public:
    DateField(std::string const& name,std::string date_format);
};



#endif

