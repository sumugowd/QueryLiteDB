#include "../include/QueryExecutor.h"
#include "../include/CreateQuery.h"
#include "../include/InsertQuery.h"
#include "../include/FileManager.h"
#include "../include/SelectQuery.h"
#include "../include/DeleteQuery.h"
#include "../include/UpdateQuery.h"
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

        // Validate column count
        if(iq->values.size() != table->getColumns().size()){
            std::cout << "Error: Column count mismatch!" << std::endl;
            return;
        }
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

    }
    // Handle DELETE
    else if(query->type == "DELETE"){
        DeleteQuery* dq = (DeleteQuery*)query;

        Table* table = db.getTable(dq->tableName);
        if(!table) return;

        table->deleteRows(dq->columnName, dq->value);

        // Save after delete
        FileManager::saveTable(*table);

        std::cout << "Delete successful!" << std::endl;
    }
    // Handle UPDATE
    else if(query->type == "UPDATE"){
        UpdateQuery* uq = (UpdateQuery*)query;

        Table* table = db.getTable(uq->tableName);
        if(!table) return;

        table->updateRows(uq->whereColumn, uq->whereValue, uq->setColumn, uq->setValue);

        // Save after update
        FileManager::saveTable(*table);

        std::cout << "Update successful!" << std::endl;
    }
    // Handle CREATE
    else if(query->type == "CREATE"){
        CreateQuery* cq = (CreateQuery*)query;

        if(db.tableExists(cq->tableName)){
            cout << "Table already exists!" << endl;
            return;
        }

        vector<Column> cols;

        for(string colName : cq->columns){
            cols.push_back(Column(colName, "STRING"));
        }

        db.createTable(cq->tableName,cols);

        cout << "Table created successfully!" << endl;
    }
    else{
        std::cout << "Query type not supported yet!" << std::endl;
    }
}