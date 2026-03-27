#ifndef DELETEQUERY_H
#define DELETEQUERY_H

#include "Query.h"

class DeleteQuery : public Query{
    public:
        string tableName;
        string columnName;
        string value;

        DeleteQuery() {
            type = "DELETE";
        }
};

#endif