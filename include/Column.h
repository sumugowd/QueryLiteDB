#ifndef COLUMN_H
#define COLUMN_H

#include<string>
using namespace std;

class Column {
    private:
        string name;
        string type;

    public:
        Column();
        Column(string name, string type);

        string getName() const;
        string getType() const;
};

#endif