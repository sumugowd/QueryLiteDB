#include "../include/QueryExecutor.h"
#include "../include/InsertQuery.h"
#include "../include/FileManager.h"
#include "../include/SelectQuery.h"
#include <iostream>

QueryExecutor::QueryExecutor(Database& database) : db(database){}

void QueryExecutor::execute(Query* query) {
    if(!query){
        std::cout << "Invalid query!" << std::endl;
        return;
    }

    // Handle INSERT
    if(query->type == "INSERT"){
        InsertQuery* iq = (InsertQuery*)query;

        Table* table = db.getTable(iq->tableName);
        if(!table) return;

        table->insertRow(Row(iq->values));

        // Save to file after insert
        FileManager::saveTable(*table);

        std::cout << "Insert successful!" << std::endl;

    }
    // Handle SELECT
    else if(query->type == "SELECT"){
        SelectQuery* sq = (SelectQuery*)query;

        Table* table = db.getTable(sq->tableName);
        if(!table) return;

        table->displayTable();
        
    }else{
        std::cout << "Query type not supported yet!" << std::endl;
    }
}