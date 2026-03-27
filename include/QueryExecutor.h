#ifndef QUERYEXECUTOR_H
#define QUERYEXECUTOR_H

#include "Query.h"
#include "Database.h"

class QueryExecutor{
    private:
        Database& db;

    public:
        QueryExecutor(Database& database);

        void execute(Query* query);
};

#endif