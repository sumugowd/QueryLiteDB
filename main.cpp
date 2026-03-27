#include <iostream>
#include "include/Table.h"

using namespace std;

int main() {
    cout << "Testing Table..." << endl;

    // Define columns
    vector<Column> columns = {
        Column("id", "INT"),
        Column("name", "STRING"),
        Column("age", "INT")
    };

    // Create table
    Table students("Students", columns);

    // Insert rows
    students.insertRow(Row({"1", "Sumu", "22"}));
    students.insertRow(Row({"2", "Ravi", "23"}));

    // Display table
    students.displayTable();
    
    return 0;
}