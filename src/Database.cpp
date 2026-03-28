#include "../include/Database.h"
#include "../include/FileManager.h"
#include <iostream>
#include <filesystem>

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

// load all tables
namespace fs = std::filesystem;

void Database::loadAllTables(){
    string folder = "data/";

    for(const auto& entry : fs::directory_iterator(folder)){
        string filePath = entry.path().string();

        //Extract table name form file
        string fileName = entry.path().filename().string();
        string tableName = fileName.substr(0,fileName.find(".txt"));

        Table table = FileManager::loadTable(tableName);

        if(table.getName() != ""){
            tables[tableName] = table;
            cout << "Loaded table: " << tableName << endl;
        }
    }
}

// Display all tables
void Database::showTables() const{
    cout << "Tables in Database:" << endl;

    for(const auto& pair : tables){
        cout << "- " << pair.first << endl;
    }
}

// table existence check
bool Database::tableExists(string tableName) const{
    return tables.find(tableName) != tables.end();
}

// file load
void Database::loadTableFromFIle(string tableName){
    Table table = FileManager::loadTable(tableName);
    
    if(table.getName() != ""){
        tables[tableName] = table;
        cout << "Loaded table: " << tableName << endl;
    }
}