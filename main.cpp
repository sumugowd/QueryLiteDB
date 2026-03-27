#include <iostream>
#include "include/Database.h"
#include "include/Tokenizer.h"
#include "include/QueryParser.h"
#include "include/QueryExecutor.h"

using namespace std;

int main() {
    Database db;

    // Create table manually (for now)
    vector<Column> columns = {
        Column("id", "INT"),
        Column("name", "STRIMG"),
        Column("age", "INT")
    };

    db.createTable("students",columns);

    QueryExecutor executor(db);

    while(true) {
        cout << "\nEnter Query (or type EXIT): ";
        string queryStr;
        getline(cin, queryStr);

        if(queryStr == "EXIT") break;

        // step 1: Tokenize
        vector<string> tokens = Tokenizer::tokenize(queryStr);

        // step 2: Parse
        Query* query = QueryParser::parse(tokens);

        // step 3: Execute
        executor.execute(query);

        // Optimal: show table after each query
        Table* table = db.getTable("students");
        if(table){
            cout << "\nCurrent Table:\n";
            table->displayTable();
        }
    }

    return 0;
}