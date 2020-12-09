//
// Created by sandw on 12/7/2020.
//

#ifndef ADVENT2020_DAY7_H
#define ADVENT2020_DAY7_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

struct bagContents
{
    std::string color;
    int count;
};

class Day7 {

public:
    int calculate1(std::vector<std::string> input);
    int calculate2(std::vector<std::string> input);
    int getBagContents(std::string name, std::vector<bagContents> *contents);
    int getBagContents2(bagContents *contents);
    std::vector<bagContents>* getBagByColor(std::string coloredBag);
};

#endif //ADVENT2020_DAY7_H
