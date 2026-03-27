#include "../include/QueryParser.h"
#include "../include/InsertQuery.h"
#include <iostream>

Query* QueryParser::parse(const vector<string>& tokens){
    if(tokens.empty()) return nullptr;

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

    cout << "Unsupported query type!" << endl;
    return nullptr;
}