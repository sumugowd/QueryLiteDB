#ifndef CREATEQUERY_H
#define CREATEQUERY_H

#include "Query.h"
#include <vector>

class CreateQuery : public Query {
    public:
        string tableName;
        vector<string> columns;

        CreateQuery() {
            type = "CREATE";
        }
};

#endif