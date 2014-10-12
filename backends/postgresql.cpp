#include <pqxx/pqxx>
#include <iostream>
#include "postgresql.h"

	
//Constructors:
PostgresqlBackend::PostgresqlBackend(){
	conn = nullptr;
}

PostgresqlBackend::PostgresqlBackend(std::map<std::string,std::string> config)
		:config( config ) 
{
	conn = nullptr;
}

//Check Connection Status
bool PostgresqlBackend::isConnected() {
    try
    {
		return (conn != NULL) && (conn->is_open());
    }
    catch (const std::exception &e)
    {
        std::cerr<<e.what();
        return false;
    }
}

//Establish connection
bool PostgresqlBackend::connect() {
	try
	{
		std::string conn_str = "user=" + config["pg_username"] + " ";
					 conn_str += "host=" + config["pg_hostname"] + " ";
					 conn_str += "password=" + config["pg_password"] + " ";
					 conn_str += "dbname=" + config["pg_dbname"] + " ";
					 conn_str += "port=" + config["pg_port"];
		conn = new pqxx::connection(conn_str);
	}
    catch (const std::exception &e)
	{
        std::cerr<<"Can't connect to db "<<e.what();
		return false;
	}
	return true;
}

//Disconnect from db
bool PostgresqlBackend::disconnect() {
	try 
	{
		if ( isConnected()) {
			conn->disconnect();
			return true;
		}
		return false;
	}
	catch (const std::exception &e)
	{
        std::cerr<<"PostresqlBackend::disconnect() failed! "<<e.what();
		return false;
	}
}

pqxx::connection* PostgresqlBackend::getConnection() { 
	return conn;
}

std::string PostgresqlBackend::getConfig(std::string key) {
	auto it = config.find(key);
	if (it != std::end(config)){
		return config[key];
	} else {
		return "UNKNOWN";
	}
}

//Destructor:
PostgresqlBackend::~PostgresqlBackend() {
	if ( conn != nullptr) {
		delete conn;
		conn = nullptr;
	}
}

