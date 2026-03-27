#include "../include/Database.h"
#include <iostream>

Database::Database() {}

// Create new table
void Database::createTable(string tableName, vector<Column> columns){
    if(tables.find(tableName) != tables.end()){
        cout << "Error: Table already exists!" << endl;
        return;
    }

    tables[tableName] = Table(tableName, columns);
    cout << "Table '" << tableName << "' created successfully." << endl;
}

// Get table pointer
Table* Database::getTable(string tableName){
    if(tables.find(tableName) == tables.end()){
        cout << "Error: Table not found!" << endl;
        return nullptr;
    }

    return &tables[tableName];
}

// Display all tables
void Database::showTables() const{
    cout << "Tables in Database:" << endl;

    for(const auto& pair : tables){
        cout << "- " << pair.first << endl;
    }
}