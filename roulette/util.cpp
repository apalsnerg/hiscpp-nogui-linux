#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

/**
 * Splits a string into a vector of individual words
 * 
 * @param strToSplit The string to split up
 */
vector<string> strSplit(string strToSplit) {
    vector<string> strToSplitArray; // Vector to contain the individual words
    string substr; // Temp string to contain the individual words during processing
    strToSplit += ' '; // Since we split on space, make sure there always is one at the end of the word
    for (int i = 0; i < strToSplit.length(); i++) {
        if (strToSplit[i] == ' ') {
            strToSplitArray.push_back(substr);
            substr = "";
        } else {
            substr += strToSplit[i];
        }
    }
    return strToSplitArray;
}