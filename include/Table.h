#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include "Row.h"
#include "Column.h"

using namespace std;

class Table{
    private:
        string tableName;
        vector<Column> columns;
        vector<Row> rows;

    public:
        Table();
        Table(string name, vector<Column> columns);

        string getName() const;

        void insertRow(const Row& row);
        void deleteRows(string columnName, string value);
        void displayTable() const;

        int getColumnIndex(string columnName) const;

        vector<Column> getColumns() const;
        vector<Row> getRows() const;
};

#endif