#include "../include/QueryParser.h"
#include "../include/CreateQuery.h"
#include "../include/InsertQuery.h"
#include "../include/SelectQuery.h"
#include "../include/DeleteQuery.h"
#include "../include/UpdateQuery.h"
#include "../include/Utils.h"
#include <iostream>

Query* QueryParser::parse(const vector<string>& tokens){
    if(tokens.empty()) return nullptr;

    // Conver keywords to uppercase
    vector<string> upperTokens = tokens;
    for(string &t : upperTokens){
        t = Utils::toUpper(t);
    }

    // Insert
    if(upperTokens[0] == "INSERT"){
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
    else if(upperTokens[0] == "SELECT"){
        SelectQuery* query = new SelectQuery();

        // SELECT * FROM table
        query->tableName = tokens[3];

        return query;

    // Delete
    }else if(upperTokens[0] == "DELETE"){
        DeleteQuery* query = new DeleteQuery();

        // DELETE FROM table WHERE column =value
        query->tableName = tokens[2];
        query->columnName = tokens[4];
        query->value = tokens[6];

        return query;
    // Update
    }else if(upperTokens[0] == "UPDATE"){
        UpdateQuery* query = new UpdateQuery();

        // UPDATE table SET col = val WHERE col = val
        query->tableName = tokens[1];
        query->setColumn = tokens[3];
        query->setValue = tokens[5];
        query->whereColumn = tokens[7];
        query->whereValue = tokens[9];

        return query;
    }else if(upperTokens[0] == "CREATE"){
        // CREATE TABLE (col1, col2, col3)
        if(tokens.size() < 5){
            cout << "Invalid CREATE syntax!" << endl;
            return nullptr;
        }

        CreateQuery* query = new CreateQuery();
        query->tableName = tokens[2];

        for(int i = 4; i < tokens.size(); i++){
            if(tokens[i] == "(" || tokens[i] == ")" || tokens[i] == ",") continue;
            query->columns.push_back(tokens[i]);
        }

        return query;
    }
    cout << "Unsupported query type!" << endl;
    return nullptr;
}