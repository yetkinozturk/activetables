#ifndef __MODEL_H__
#define __MODEL_H__
#include <set>
#include <list>
#include <vector>
#include "field.h"
#include "queryset.h"

enum ModelStatus
{
    INITIAL,
    CREATED_NOT_SAVED,
    CREATED,
    SAVED,
    UPDATED_NOT_SAVED,
    LOADED
};
class Model
{
private:
    std::hash<std::string> __hash_fn;

protected:
    std::set<Field> __field_list;
    std::set<Field> __updated_field_list;
    std::set<Field> __primary_key_list;
    std::set<std::set<Field> > __index_list;
    ModelStatus __model_status;
    std::string __table_name;
    size_t __id;

public:
    Model(const std::string &model_name);
    virtual void set_pk(const std::set<Field> &pk_list);
    virtual void set_index(const std::set<Field> &idx_list,bool unique=false);
    virtual QuerySet filter(std::string condition);
    virtual QuerySet get(std::string condition);
    virtual QuerySet all();
    virtual void set_table_name(const std::string &table_name);
    virtual std::string get_table_name();
    virtual void save();
    virtual void load_from_sql(std::string condition);
    virtual void init();
    virtual void init_meta_model();
    virtual void load_from_meta_model();
    virtual ~Model();
};



#endif

