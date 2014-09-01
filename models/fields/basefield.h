#ifndef __FIELD_H__
#define __FIELD_H__

#include <string>
#define unique_true true

enum FieldType { COMMONFIELD, CHARFIELD, NUMBERFIELD, DATEFIELD };

class Field {
private:
    std::hash<std::string> hash_fn;
public:
	Field(){}
	Field (std::string const& name,FieldType type);
	virtual Field& max_length(const size_t& len);
	virtual Field& min_length(const size_t& len);
	virtual Field& null_true();
	virtual Field& blank_true();
	virtual Field& default_value(const std::string & default_value );
	virtual size_t get_max_length() { return _max_length; }
	virtual size_t get_min_length() { return _min_length; }
	virtual bool is_null_true() { return _null_true; }
	virtual bool is_blank_true() { return _blank_true; }
	virtual FieldType get_field_type () { return _type; }
    virtual bool operator < (const Field &f) const { return this->_id < f._id; }
	virtual ~Field();
protected:
    size_t _id;
	FieldType _type;
	std::string _name;
	std::string _default_value;
	size_t _max_length;
	size_t _min_length;
	bool _null_true;
	bool _blank_true;
};


#endif

