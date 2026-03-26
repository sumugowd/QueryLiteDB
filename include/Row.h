#ifndef ROW_H
#define ROW_H

#include <vector>
#include <string>
using namespace std;

class Row{
    private:
        vector<string> values;

    public:
        Row();
        Row(vector<string> values);

        vector<string> getValues() const;
        string getValue(int index) const;

        void setValue(int index, string value);
};

#endif