#include "../include/Column.h"

Column::Column(){}

Column::Column(string name, string type){
    this->name = name;
    this->type = type;
}

string Column::getName() const{
    return name;
}

string Column::getType() const{
    return type;
}