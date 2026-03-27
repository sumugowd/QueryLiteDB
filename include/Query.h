#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>

using namespace std;

class Query {
    public:
        string type;
        virtual ~Query(){}
};

#endif