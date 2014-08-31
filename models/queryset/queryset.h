#ifndef __QUERYSET_H__
#define __QUERYSET_H__


template <class T> 
class BaseQuerySet
{
private:
	std::vector<T> vector_of_items;
	std::list<T> list_of_items;
public:
	BaseQuerySet();
};

template <class T>
BaseQuerySet<T>::BaseQuerySet(){}

class Model;
typedef BaseQuerySet<Model> QuerySet;

#endif
