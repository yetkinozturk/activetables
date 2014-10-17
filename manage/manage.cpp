#include <iostream>
#include <gflags/gflags.h>
#include <gflags/gflags_completions.h>

DEFINE_bool( usage,    false, "Print brief usage information" );
DEFINE_bool( check,    false, "Check Models" );
DEFINE_bool( checkall, false, "Check Models and DB." );
DEFINE_bool( printsql, false, "Print SQL Representation" );
DEFINE_bool( syncdb,   false, "Sync Models to DB. (create)" );
DEFINE_bool( flush,    false, "Empty all records for Models on DB. (truncate)" );
DEFINE_bool( rebuild,  false, "Drop All DB Schemas and Rebuild Them. (drop)" );

DEFINE_string( options, "usage,check,checkall,printsql,syncdb,flush,rebuild",
               "What are the options for Manage.app" );

int main( int argc, char** argv )
{

  google::SetUsageMessage( "Manage.app for your ORM." );
  google::ParseCommandLineFlags( &argc, &argv, 0);
  google::HandleCommandLineCompletions();

  //Validate paramters, only one main parameter can be used at a time. Optional flags can be added.
  const bool valid_params = FLAGS_usage ^ FLAGS_check ^ FLAGS_checkall ^
                            FLAGS_printsql ^ FLAGS_syncdb ^ FLAGS_flush ^
                            FLAGS_rebuild;

  const short valid_param_sum = FLAGS_usage + FLAGS_check + FLAGS_checkall +
                                FLAGS_printsql + FLAGS_syncdb + FLAGS_flush +
                                FLAGS_rebuild;

  if( argc == 1 or valid_param_sum == 0)
  {

    //Print Brief Usage.
    //...

  } else if (valid_params) {

        if (FLAGS_usage) {
            //...
        } else if (FLAGS_check) {
            //...
        } else if (FLAGS_checkall) {    
            //...
        } else if (FLAGS_printsql) {        
            //...
        } else if (FLAGS_syncdb) {
            //...
        } else if (FLAGS_flush) {        
            //...
        } else if (FLAGS_rebuild) {        
            //...
        }
        else {
            std::cerr<<"Fix me :(";
        }

    } else {
        std::cerr<<"only one main parameter can be used at a time. "
                       "Optional flags can be added."<<std::endl;
    }

  return 0;
}
