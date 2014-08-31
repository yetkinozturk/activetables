#ifndef __MODEL_H__
#define __MODEL_H__
#include <set>
#include <list>
#include <vector>
#include "models/fields/field.h"
#include "models/queryset/queryset.h"


class Model
{
private:
	std::vector<Field> field_list;
	std::set<Field > primary_key;
	std::set< std::set<Field> > index_list;
	QuerySet get(std::string);
public:
	Model();
};



#endif

