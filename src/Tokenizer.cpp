#include "../include/Tokenizer.h"
#include <sstream>
#include <cctype>

vector<string> Tokenizer::tokenize(const string& query){
    vector<string> tokens;
    string token;

    for(char ch : query){
        if(isspace(ch)){
            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }
        }else if(ch == ',' || ch == '(' || ch == ')'){
            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, ch));
        }else{
            token += ch;
        }
    }
    if(!token.empty()){
        tokens.push_back(token);
    }

    return tokens;
}