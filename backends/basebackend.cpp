#include <string>
#include <map>
#include <list>
#include "basebackend.h"

	
//Constructors:
Backend::Backend(){

}

Backend::Backend(std::map<std::string,std::string> config)
		:config( config ) 
{

}


std::string Backend::getConfig(std::string key) {
	auto it = config.find(key);
	if (it != std::end(config)){
		return config[key];
	} else {
		return "UNKNOWN";
	}
}

//Destructor:
Backend::~Backend() {
}

