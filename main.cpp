#include <iostream>
#include "include/Database.h"
#include "include/FileManager.h"

using namespace std;

int main() {
    Database db;

    vector<Column> columns = {
        Column("id", "INT"),
        Column("name", "STRING"),
        Column("age", "INT")
    };

    db.createTable("students", columns);

    Table* students = db.getTable("students");

    if(students != nullptr){
        students->insertRow(Row({"1", "Sumu", "22"}));
        students->insertRow(Row({"2", "Ravi", "23"}));

        // SAVE to file
        FileManager::saveTable(*students);
    }
    
    cout << "\nReloading from file...\n" << endl;

    // LOAD from file
    Table loadedTable = FileManager::loadTable("students");
    loadedTable.displayTable();
    
    return 0;
}