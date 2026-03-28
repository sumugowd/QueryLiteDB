#include "../include/Utils.h"
#include <algorithm>
#include <cctype>

// Convert to uppercase
string Utils::toUpper(string str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Trim spaces
string Utils::trim(string str){
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
    return str;
}