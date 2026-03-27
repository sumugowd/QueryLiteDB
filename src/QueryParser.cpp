#include "../include/QueryParser.h"
#include "../include/InsertQuery.h"
#include "../include/SelectQuery.h"
#include "../include/DeleteQuery.h"
#include <iostream>

Query* QueryParser::parse(const vector<string>& tokens){
    if(tokens.empty()) return nullptr;

    // Insert
    if(tokens[0] == "INSERT"){
        InsertQuery* query = new InsertQuery();

        // INSERT INTO table VALUES (...)
        query->tableName = tokens[2];

        for(int i = 5; i < tokens.size(); i++){
            if(tokens[i] == "(" || tokens[i] == ")" || tokens[i] == ",") continue;
            query->values.push_back(tokens[i]);
        }

        return query;
    }

    // Select
    else if(tokens[0] == "SELECT"){
        SelectQuery* query = new SelectQuery();

        // SELECT * FROM table
        query->tableName = tokens[3];

        return query;

    // Delete
    }else if(tokens[0] == "DELETE"){
        DeleteQuery* query = new DeleteQuery();

        // DELETE FROM table WHERE column =value
        query->tableName = tokens[2];
        query->columnName = tokens[4];
        query->value = tokens[6];

        return query;
    }
    cout << "Unsupported query type!" << endl;
    return nullptr;
}