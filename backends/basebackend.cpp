#include <string>
#include <map>
#include <list>
#include "basebackend.h"

	
//Constructors:
DBBackend::DBBackend(){

}

DBBackend::DBBackend(std::map<std::string,std::string> config)
		:config( config ) 
{

}


std::string DBBackend::getConfig(std::string key) {
	auto it = config.find(key);
	if (it != std::end(config)){
		return config[key];
	} else {
		return "UNKNOWN CONFIGURATION OPTION";
	}
}

//Destructor:
DBBackend::~DBBackend() {
}

