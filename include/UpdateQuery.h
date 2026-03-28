#ifndef UPDATEQUERY_H
#define UPDATEQUERY_H

#include "Query.h"

class UpdateQuery : public Query {
    public:
        string tableName;
        string setColumn;
        string setValue;
        string whereColumn;
        string whereValue;

        UpdateQuery() {
            type = "UPDATE";
        }
};

#endif