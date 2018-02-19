#include <vector>
#include <list>
#include <set>
#include <stdarg.h>
#include "model.h"

Model::Model(const std::string &model_name)
    :__model_status(INITIAL),
     __table_name(model_name)
{
    __id = __hash_fn(model_name);
}

void Model::set_table_name(const std::string & table_name)
{
    __table_name = table_name;
}

std::string Model::get_table_name()
{
    return __table_name;
}

void Model::set_pk(const std::set<Field> &pk_list)
{

}

void Model::set_index(const std::set<Field> &index_list,bool unique)
{

}

QuerySet Model::get(std::string)
{
	QuerySet q = QuerySet();
	return q;
}

QuerySet Model::filter(std::string condition)
{
    QuerySet q = QuerySet();
    return q;
}

QuerySet Model::all()
{
    QuerySet q = QuerySet();
    return q;
}

void Model::save()
{

}

void Model::load_from_sql(std::string condition)
{
    
}

Model::~Model()
{

}

void Model::init()
{

}

void Model::init_meta_model()
{

}

void Model::load_from_meta_model()
{

}

