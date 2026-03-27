#ifndef SELECTQUERY_H
#define SELECTQUERY_H

#include "Query.h"

class SelectQuery : public Query {
    public:
        string tableName;

        SelectQuery(){
            type = "SELECT";
        }
};

#endif