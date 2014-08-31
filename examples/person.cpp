#include "person.h"

Person::Person():Model()
{
	id = NumberField("id")
			.set_as_pk()
			.max_length(2000000);

    username = CharField("username")
               	.max_length(255);

    password = CharField("password")
               	.max_length(255);

    name = CharField("name")
           	.max_length(255);

    lastname = CharField("lastname")
                .max_length(255);

	job = CharField("job")
                .null_true()
                .blank_true()
                .max_length(255)
                .default_value(""); 

};


