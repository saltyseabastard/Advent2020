//
// Created by sandw on 12/6/2020.
//

#ifndef ADVENT2020_DAY6_H
#define ADVENT2020_DAY6_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

class Day6 {
public:
    int calculate1(std::vector<std::string> input);
    int calculate2(std::vector<std::string> input);
};

struct YesCount
{
    char letter;
    int count;
};

#endif //ADVENT2020_DAY6_H
