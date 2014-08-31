#include <string>
#include "basefield.h"

Field::Field (std::string const& name, FieldType type) : _type(type), _name(name), _null_true(false), _blank_true(false), _is_pk(false) {

}

inline Field& Field::max_length(const size_t& len) {
	_max_length = len;
	return *this;
}

inline Field& Field::min_length(const size_t& len) {
	_min_length = len;
	return *this;
}

inline Field& Field::null_true() {
	_null_true = true;
	return *this;
}

inline Field& Field::blank_true() {
	_blank_true = true;
	return *this;
}

inline Field& Field::default_value (const std::string&  default_value) {
	_default_value = default_value;
	return *this;
}

inline Field& Field::set_as_pk() {
	_is_pk = true;
	return *this;
}
Field::~Field(){}

