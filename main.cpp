#include <iostream>
#include "include/Table.h"
#include "include/Database.h"

using namespace std;

int main() {
    cout << "Testing Table..." << endl;

    Database db;

    // Create table
    vector<Column> columns = {
        Column("id", "INT"),
        Column("name", "STRING"),
        Column("age", "INT")
    };

    db.createTable("students", columns);

    // show tables
    db.showTables();

    // Insert into table
    Table* students = db.getTable("students");
    if(students != nullptr){
        students->insertRow(Row({"1", "Sumu", "22"}));
        students->insertRow(Row({"2", "Ravi", "23"}));

        students->displayTable();
    }
    
    return 0;
}