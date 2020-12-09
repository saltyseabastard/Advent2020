//
// Created by sandw on 12/1/2020.
//

#ifndef ADVENT2020_UTILITIES_H
#define ADVENT2020_UTILITIES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Utilities {

    public:
        static vector<int> getIntVectorFromFile(string filename);
        static vector<string> getStringVectorFromFile(string filename);
        static vector<std::string> split(const std::string &text, char sep);
};


#endif //ADVENT2020_UTILITIES_H
