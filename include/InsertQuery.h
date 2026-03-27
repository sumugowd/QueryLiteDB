#ifndef INSERTQUERY_H
#define INSERTQUERLY_H

#include "Query.h"
class InsertQuery : public Query {
    public:
        string tableName;
        vector<string> values;

        InsertQuery(){
            type = "INSERT";
        }
};

#endif