#include "../include/Row.h"

Row::Row(){}

Row::Row(vector<string> values){
    this->values = values;
}

vector<string> Row::getValues() const{
    return values;
}

string Row::getValue(int index) const{
    if(index < 0 || index >= values.size()){
        return "";
    }
    return values[index];
}

void Row::setValue(int index, string value){
    if(index >= 0 && index < values.size()){
        values[index] = value;
    }
}