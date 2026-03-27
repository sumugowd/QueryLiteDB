#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// save table to file
void FileManager::saveTable(const Table& table){
    string filePath = "data/" + table.getName() + ".txt";
    ofstream file(filePath);

    if(!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // write columns
    vector<Column> columns = table.getColumns();
    for(int i = 0; i < columns.size(); i++){
        file << columns[i].getName();
        if(i != columns.size() - 1) file << ",";
    }
    file << endl;

    // write rows
    vector<Row> rows = table.getRows();
    for(const Row& row : rows){
        vector<string> values = row.getValues();
        for(int i = 0; i < values.size(); i++){
            file << values[i];
            if(i != values.size() - 1) file << ",";
        }
        file << endl;
    }

    file.close();
}

// load table from file
Table FileManager::loadTable(const string& tableName){
    string filePath = "data/" + tableName + ".txt";
    ifstream file(filePath);

    if(!file) {
        cout << "Error: File not found!" << endl;
        return Table();
    }

    string line;

    // Read columns
    getline(file, line);
    stringstream ss(line);
    string colName;
    vector<Column> columns;

    while(getline(ss, colName, ',')){
        columns.push_back(Column(colName, "STRING"));
    }
    Table table(tableName, columns);

    // Read rows
    while(getline(file, line)){
        stringstream rowStream(line);
        string value;
        vector<string> values;

        while(getline(rowStream, value, ',')){
            values.push_back(value);
        }

        table.insertRow(Row(values));
    }

    file.close();
    return table;
}