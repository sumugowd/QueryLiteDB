#include <iostream>
#include "include/Database.h"
#include "include/Tokenizer.h"
#include "include/QueryParser.h"
#include "include/QueryExecutor.h"
#include "include/Utils.h"

using namespace std;

int main() {
    Database db;

    // Try loading first
    db.loadTableFromFIle("students");

    // If not loaded create new
    if(!db.tableExists("students")){
        vector<Column> columns = {
            Column("id", "INT"),
            Column("name", "STRIMG"),
            Column("age", "INT")
        };

        db.createTable("students",columns);
    }

    QueryExecutor executor(db);

    while(true) {
        cout << "\nEnter Query (or type EXIT): ";
        string queryStr;
        getline(cin, queryStr);
        
        string trimmed = Utils::trim(queryStr);
        string upperInput = Utils::toUpper(trimmed);

        if(upperInput == "EXIT") break;

        // step 1: Tokenize
        vector<string> tokens = Tokenizer::tokenize(queryStr);

        // step 2: Parse
        Query* query = QueryParser::parse(tokens);

        // step 3: Execute
        executor.execute(query);
    }

    return 0;
}