#include <iostream>
#include "include/Tokenizer.h"
#include "include/QueryParser.h"
#include "include/InsertQuery.h"

using namespace std;

int main() {
    string queryStr = "INSERT INTO students VALUES(1, Sumu, 22)";

    vector<string> tokens = Tokenizer::tokenize(queryStr);

    Query* q = QueryParser::parse(tokens);

    if(q && q->type == "INSERT"){
        InsertQuery* iq = (InsertQuery*)q;

        cout << "Table: " << iq->tableName << endl;
        cout << "Values: ";

        for(string v : iq->values){
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}