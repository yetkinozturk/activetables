#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

#include <string>
#include <libconfig.h++>

#define EXIT_FAILURE -1

const static std::string VERSION = "version";
const static std::string ACTIVE_TABLES = "activetables";
const static std::string BACKEND_OPTIONS = "backend_options";
const static std::string BACKEND = "backend";
const static std::string USERNAME = "username";
const static std::string PASSWORD = "password";
const static std::string PORT = "port";
const static std::string HOST = "host";
const static std::string DBNAME = "dbname";
const static std::string MODEL_LIST = "model_list";

using namespace libconfig;

std::pair< std::map<std::string,std::string>,std::vector<std::string> > getConfiguration();

#endif
