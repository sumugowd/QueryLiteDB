#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include<string>
#include "Table.h"

using namespace std;

class Database {
    private:
        map<string, Table> tables;

    public:
        Database();

        void createTable(string tableName, vector<Column> columns);
        Table* getTable(string tableName);
        void showTables() const;
};

#endif