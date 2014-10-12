#ifndef __BASE_BACK_H__
#define __BASE_BACK_H__

#include <list>

class Backend
{

private:
    std::map<std::string,std::string> config;
public:

    //Constructors:
    Backend();

    Backend(std::map<std::string,std::string> config);
    
    //Get specific config
    std::string getConfig(std::string key);

    //Check Connection Status
    virtual bool isConnected() = 0;

    //Connect to db
    virtual bool connect() = 0;

    //db operations
    //Execute and fetch N x M rows into resultList, optionally can be limit.
    virtual bool executeAndFetch(std::string query, 
                                 std::list<std::list<std::string> > resultList,
                                 int limit=0) = 0;

    //Execute and return the status of query
    virtual bool executeOnly(std::string sql) = 0;

    //Disconnect from db
    virtual bool disconnect() = 0;

    //Destructor:
    virtual ~Backend();

};

#endif
