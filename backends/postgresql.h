#ifndef __POSTGRESQL_BACK_H__   
#define __POSTGRESQL_BACK_H__

#include "basebackend.h"

class PostgresqlBackend : public DBBackend
{

private:
	pqxx::connection *conn;
	std::map<std::string,std::string> config;
public:
	
	//Constructors:
	PostgresqlBackend();

	PostgresqlBackend(std::map<std::string,std::string> config);

	//Check Connection Status
	bool isConnected();

	//Connect to db
	bool connect();

    //Execute and fetch N x M rows into resultList, optionally can be limit.
    bool executeAndFetch(std::string query,
                                 std::list<std::list<std::string> > resultList,
                                 int limit=0);

    //Execute and return the status of query
    bool executeOnly(std::string sql);

	//Disconnect from db
	bool disconnect();

	//Get connection handler
	pqxx::connection* getConnection();

	//Get specific config
	std::string getConfig(std::string key);

	//Destructor:
	~PostgresqlBackend();

};

#endif 
