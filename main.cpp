#include <iostream>
#include "include/Column.h"
#include "include/Row.h"

using namespace std;

int main() {
    cout << "Testing Row and Column..." << endl;

    // Create columns
    Column col1("id","INT");
    Column col2("name", "STRING");

    cout << col1.getName() << " - " << col1.getType() << endl;
    cout << col2.getName() << " - " << col2.getType() << endl;

    // Create row
    vector<string> values = {"1", "Sumu"};
    Row row(values);

    cout << "Row Data: ";
    for(string val : row.getValues()){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}