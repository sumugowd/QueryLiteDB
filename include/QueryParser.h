#ifndef QUERYPARSER_H
#define QUERYPARSER_H

#include <vector>
#include <string>
#include "Query.h"

using namespace std;

class QueryParser {
    public:
        static Query* parse(const vector<string>& tokens);
};

#endif