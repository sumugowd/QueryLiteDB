#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Table.h"

using namespace std;

class FileManager {
    public:
        static void saveTable(const Table& table);
        static Table loadTable(const string& tableName);
};

#endif