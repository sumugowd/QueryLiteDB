#include "../include/Table.h"
#include <iostream>

Table::Table() {}

Table::Table(string name, vector<Column> columns){
    this->tableName = name;
    this->columns = columns;
}

string Table::getName() const{
    return tableName;
}

// Insert row with validation
void Table::insertRow(const Row& row){
    if(row.getValues().size() != columns.size()){
        cout << "Error: Column count mismatch!" << endl;
        return;
    }
    rows.push_back(row);
}

//Display all data
void Table::displayTable() const{
    // Print Column headers
    for(const Column& col : columns){
        cout << col.getName() << "\t";
    }
    cout << endl;

    // print rows
    for(const Row& row : rows){
        for(const string& val : row.getValues()){
            cout << val << "\t";
        }
        cout << endl;
    }
}

// Get column index by name
int Table::getColumnIndex(string columnName) const{
    for(int i = 0; i < columns.size(); i++){
        if(columns[i].getName() == columnName){
            return i;
        }
    }
    return -1;
}

vector<Column> Table::getColumns() const{
    return columns;
}

vector<Row> Table::getRows() const {
    return rows;
}