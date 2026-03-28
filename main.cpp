#include <iostream>
#include "include/Database.h"
#include "include/Tokenizer.h"
#include "include/QueryParser.h"
#include "include/QueryExecutor.h"
#include "include/Utils.h"

using namespace std;

int main() {
    Database db;

    // Auto load all tables
    db.loadAllTables();

    QueryExecutor executor(db);

    cout << "============================\n";
    cout << "==== QueryLiteDB Engine ====\n";
    cout << "============================\n";
    
    while(true) {
        cout << "\nQueryLiteDB > ";

        string queryStr;
        getline(cin, queryStr);
        
        string trimmed = Utils::trim(queryStr);
        string upperInput = Utils::toUpper(trimmed);

        if(upperInput == "EXIT"){
            cout << "Exiting QueryLiteDB....\n";
            break;
        }

        // Empty input
        if(trimmed.empty()){
            cout << "Empty query!" << endl;
            continue;
        }

        // step 1: Tokenize
        vector<string> tokens = Tokenizer::tokenize(queryStr);

        // step 2: Parse
        Query* query = QueryParser::parse(tokens);

        if(!query){
            cout << "Invalid query syntax!" << endl;
            continue;
        }

        // step 3: Execute
        executor.execute(query);
    }

    return 0;
}