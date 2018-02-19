activetables
============
Active Record implementation in C++ with a Django ORM like fashion.

Active Record: http://www.martinfowler.com/eaaCatalog/activeRecord.html

Django ORM: https://docs.djangoproject.com/en/dev/topics/db/models/


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


    Person::Person():Model("Person")
    {
        id = NumberField("id")
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

        set_pk({id});
        set_index({name,username},unique_true);
        set_index({job});
    };


Dependencies:
============

Project's first target is Postgresql.

For OSX with homebrew

brew install log4cxx libpqxx libconfig gflags

For Debian based Linux distros:

sudo apt-get install cmake libpqxx3-dev libgflags-dev liblog4cxx10-dev


    mkdir build
    cd build
    cmake ../
    make
